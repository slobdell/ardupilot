#include <stdio.h>
#include "custom_main.h"
#include "PID.h"
#include "filters.h"
#include <cmath> // For M_PI

// =============================================================================
// --- TEST-SPECIFIC CONFIGURATION ---
// =============================================================================
const TVC_Config tvc_test_config = {
    .pitch_rate_low   = {0.002, 0.0036, 0.00001},
    .pitch_rate_high  = {0.001, 0.0036, 0.000005},
    .roll_rate_low    = {0.001, 0.001, 0.000005},
    .roll_rate_high   = {0.0005, 0.001, 0.000002},
    .pitch_angle      = {1.0, 0.0, 0.01},
    .roll_angle       = {1.0, 0.0, 0.01},
    .i_max_angle      = 100.0,
    .i_max_pitch_rate = 240.0,
    .i_max_roll_rate  = 500.0
};

// A simple assertion function for testing
void assert_equals_float(float expected, float actual, float tolerance, const char* message) {
    if (actual < (expected - tolerance) || actual > (expected + tolerance)) {
        printf("Assertion FAILED: %s. Expected %f, got %f\n", message, expected, actual);
    } else {
        printf("Assertion PASSED: %s.\n", message);
    }
}

void assert_equals_int(int expected, int actual, const char* message) {
    if (expected != actual) {
        printf("Assertion FAILED: %s. Expected %d, got %d\n", message, expected, actual);
    } else {
        printf("Assertion PASSED: %s.\n", message);
    }
}

// A function to check if a value is greater than a threshold
void assert_greater_than(float threshold, float actual, const char* message) {
    if (actual <= threshold) {
        printf("Assertion FAILED: %s. Expected > %f, got %f\n", message, threshold, actual);
    } else {
        printf("Assertion PASSED: %s.\n", message);
    }
}

// A function to check if a value is greater than or equal to a threshold
void assert_greater_than_or_equal(float threshold, float actual, const char* message) {
    if (actual < threshold) {
        printf("Assertion FAILED: %s. Expected >= %f, got %f\n", message, threshold, actual);
    } else {
        printf("Assertion PASSED: %s.\n", message);
    }
}

void assert_true(bool actual, const char* message) {
    if (!actual) {
        printf("Assertion FAILED: %s. Expected true, got false\n", message);
    } else {
        printf("Assertion PASSED: %s.\n", message);
    }
}

void assert_false(bool actual, const char* message) {
    if (actual) {
        printf("Assertion FAILED: %s. Expected false, got true\n", message);
    } else {
        printf("Assertion PASSED: %s.\n", message);
    }
}


void run_zero_input_test() {
    printf("\n--- Running Test Case: Zero Inputs (Hover) ---\n");

    // 1. Setup state objects
    LinearPIDController pitch_rate_pid(tvc_test_config.pitch_rate_low.p, tvc_test_config.pitch_rate_low.i, tvc_test_config.pitch_rate_low.d, tvc_test_config.i_max_pitch_rate);
    LinearPIDController roll_rate_pid(tvc_test_config.roll_rate_low.p, tvc_test_config.roll_rate_low.i, tvc_test_config.roll_rate_low.d, tvc_test_config.i_max_roll_rate);
    LinearPIDController pitch_angle_pid(tvc_test_config.pitch_angle.p, tvc_test_config.pitch_angle.i, tvc_test_config.pitch_angle.d, tvc_test_config.i_max_angle);
    LinearPIDController roll_angle_pid(tvc_test_config.roll_angle.p, tvc_test_config.roll_angle.i, tvc_test_config.roll_angle.d, tvc_test_config.i_max_angle);
    CustomFilter target_pitch_rate_filter(25.0f, 1.0f/400.0f, IIR::OD2);
    CustomFilter target_roll_rate_filter(25.0f, 1.0f/400.0f, IIR::OD2);

    TVC_State state = {
        pitch_rate_pid, roll_rate_pid, pitch_angle_pid, roll_angle_pid,
        target_pitch_rate_filter, target_roll_rate_filter,
        false, false
    };
    state.pitch_angle_pid.reset();
    state.roll_angle_pid.reset();
    state.pitch_rate_pid.reset();
    state.roll_rate_pid.reset();

    // 2. Setup mock inputs
    TVC_Inputs inputs = {};
    inputs.ahrs_healthy = true;
    inputs.in_failsafe = false;
    inputs.now_us = 0;

    for (int i = 0; i < 6; i++) {
        inputs.rc_in[i] = 1100;
    }
    inputs.rc_in[6] = 1000; // Thrust (0%)
    inputs.rc_in[7] = 1500; // Forward (neutral)
    inputs.rc_in[8] = 1500; // Lateral (neutral)
    inputs.gyro = {0.0f, 0.0f, 0.0f};
    inputs.pitch_rad = 0.0f;
    inputs.roll_rad = 0.0f;

    // 3. Call the core logic function
    TVC_Outputs outputs = tvc_run_main_logic(inputs, state, tvc_test_config);

    // 4. Assert the expected outputs
    assert_equals_float(0.0f, outputs.debug_data.vector_pitch_out, 0.001, "Pitch command should be zero");
    assert_equals_float(0.0f, outputs.debug_data.vector_roll_out, 0.001, "Roll command should be zero");
    assert_equals_float(1.0f, outputs.debug_data.thrust_factor, 0.001, "Thrust factor should be 1.0");
}

void run_full_forward_test() {
    printf("\n--- Running Test Case: Full Forward Command ---\n");

    // 1. Setup state
    LinearPIDController pitch_rate_pid(tvc_test_config.pitch_rate_low.p, tvc_test_config.pitch_rate_low.i, tvc_test_config.pitch_rate_low.d, tvc_test_config.i_max_pitch_rate);
    LinearPIDController roll_rate_pid(tvc_test_config.roll_rate_low.p, tvc_test_config.roll_rate_low.i, tvc_test_config.roll_rate_low.d, tvc_test_config.i_max_roll_rate);
    LinearPIDController pitch_angle_pid(tvc_test_config.pitch_angle.p, tvc_test_config.pitch_angle.i, tvc_test_config.pitch_angle.d, tvc_test_config.i_max_angle);
    LinearPIDController roll_angle_pid(tvc_test_config.roll_angle.p, tvc_test_config.roll_angle.i, tvc_test_config.roll_angle.d, tvc_test_config.i_max_angle);
    CustomFilter target_pitch_rate_filter(25.0f, 1.0f/400.0f, IIR::OD2);
    CustomFilter target_roll_rate_filter(25.0f, 1.0f/400.0f, IIR::OD2);

    TVC_State state = {
        pitch_rate_pid, roll_rate_pid, pitch_angle_pid, roll_angle_pid,
        target_pitch_rate_filter, target_roll_rate_filter,
        false, false
    };
    state.pitch_angle_pid.reset();
    state.roll_angle_pid.reset();
    state.pitch_rate_pid.reset();
    state.roll_rate_pid.reset();

    // 2. Setup mock inputs
    TVC_Inputs inputs = {};
    inputs.ahrs_healthy = true;
    inputs.in_failsafe = false;
    inputs.now_us = 0;
    for (int i = 0; i < 6; i++) {
        inputs.rc_in[i] = 1100;
    }
    inputs.rc_in[6] = 1500; // Mid-level thrust
    inputs.rc_in[7] = 2000; // Full forward command
    inputs.rc_in[8] = 1500; // Neutral lateral command
    inputs.gyro = {0.0f, 0.0f, 0.0f};
    inputs.pitch_rad = 0.0f;
    inputs.roll_rad = 0.0f;

    // 3. Run logic multiple times to allow PIDs to respond
    TVC_Outputs outputs;
    for (int i = 0; i < 100; ++i) {
        inputs.now_us += 2500; // 400Hz
        outputs = tvc_run_main_logic(inputs, state, tvc_test_config);
    }

    // 4. Assert the expected outputs
    assert_greater_than_or_equal(0.1, outputs.debug_data.vector_pitch_out, "Pitch command should be positive");
    assert_equals_float(0.0f, outputs.debug_data.vector_roll_out, 0.001, "Roll command should be zero");
    assert_greater_than(1.0, outputs.debug_data.thrust_factor, "Thrust factor should be > 1.0");
}


void run_full_lateral_test() {
    printf("\n--- Running Test Case: Full Lateral Command ---\n");

    // 1. Setup state
    LinearPIDController pitch_rate_pid(tvc_test_config.pitch_rate_low.p, tvc_test_config.pitch_rate_low.i, tvc_test_config.pitch_rate_low.d, tvc_test_config.i_max_pitch_rate);
    LinearPIDController roll_rate_pid(tvc_test_config.roll_rate_low.p, tvc_test_config.roll_rate_low.i, tvc_test_config.roll_rate_low.d, tvc_test_config.i_max_roll_rate);
    LinearPIDController pitch_angle_pid(tvc_test_config.pitch_angle.p, tvc_test_config.pitch_angle.i, tvc_test_config.pitch_angle.d, tvc_test_config.i_max_angle);
    LinearPIDController roll_angle_pid(tvc_test_config.roll_angle.p, tvc_test_config.roll_angle.i, tvc_test_config.roll_angle.d, tvc_test_config.i_max_angle);
    CustomFilter target_pitch_rate_filter(25.0f, 1.0f/400.0f, IIR::OD2);
    CustomFilter target_roll_rate_filter(25.0f, 1.0f/400.0f, IIR::OD2);

    TVC_State state = {
        pitch_rate_pid, roll_rate_pid, pitch_angle_pid, roll_angle_pid,
        target_pitch_rate_filter, target_roll_rate_filter,
        false, false
    };
    state.pitch_angle_pid.reset();
    state.roll_angle_pid.reset();
    state.pitch_rate_pid.reset();
    state.roll_rate_pid.reset();

    // 2. Setup mock inputs
    TVC_Inputs inputs = {};
    inputs.ahrs_healthy = true;
    inputs.in_failsafe = false;
    inputs.now_us = 0;
    for (int i = 0; i < 6; i++) {
        inputs.rc_in[i] = 1100;
    }
    inputs.rc_in[6] = 1500; // Mid-level thrust
    inputs.rc_in[7] = 1500; // Neutral forward command
    inputs.rc_in[8] = 2000; // Full lateral command
    inputs.gyro = {0.0f, 0.0f, 0.0f};
    inputs.pitch_rad = 0.0f;
    inputs.roll_rad = 0.0f;

    // 3. Run logic multiple times to allow PIDs to respond
    TVC_Outputs outputs;
    for (int i = 0; i < 100; ++i) {
        inputs.now_us += 2500; // 400Hz
        outputs = tvc_run_main_logic(inputs, state, tvc_test_config);
    }

    // 4. Assert the expected outputs
    assert_equals_float(0.0f, outputs.debug_data.vector_pitch_out, 0.001, "Pitch command should be zero");
    assert_greater_than_or_equal(0.1, outputs.debug_data.vector_roll_out, "Roll command should be positive");
    assert_greater_than(1.0, outputs.debug_data.thrust_factor, "Thrust factor should be > 1.0");
}

void run_saturation_test() {
    printf("\n--- Running Test Case: Saturation Test ---\n");

    // 1. Setup state
    LinearPIDController pitch_rate_pid(tvc_test_config.pitch_rate_low.p, tvc_test_config.pitch_rate_low.i, tvc_test_config.pitch_rate_low.d, tvc_test_config.i_max_pitch_rate);
    LinearPIDController roll_rate_pid(tvc_test_config.roll_rate_low.p, tvc_test_config.roll_rate_low.i, tvc_test_config.roll_rate_low.d, tvc_test_config.i_max_roll_rate);
    LinearPIDController pitch_angle_pid(tvc_test_config.pitch_angle.p, tvc_test_config.pitch_angle.i, tvc_test_config.pitch_angle.d, tvc_test_config.i_max_angle);
    LinearPIDController roll_angle_pid(tvc_test_config.roll_angle.p, tvc_test_config.roll_angle.i, tvc_test_config.roll_angle.d, tvc_test_config.i_max_angle);
    CustomFilter target_pitch_rate_filter(25.0f, 1.0f/400.0f, IIR::OD2);
    CustomFilter target_roll_rate_filter(25.0f, 1.0f/400.0f, IIR::OD2);

    TVC_State state = {
        pitch_rate_pid, roll_rate_pid, pitch_angle_pid, roll_angle_pid,
        target_pitch_rate_filter, target_roll_rate_filter,
        false, false
    };
    state.pitch_angle_pid.reset();
    state.roll_angle_pid.reset();
    state.pitch_rate_pid.reset();
    state.roll_rate_pid.reset();

    // 2. Setup mock inputs
    TVC_Inputs inputs = {};
    inputs.ahrs_healthy = true;
    inputs.in_failsafe = false;
    inputs.now_us = 0;
    // Set a high base throttle to induce saturation
    for (int i = 0; i < 6; i++) {
        inputs.rc_in[i] = 1900; // 90% throttle
    }
    inputs.rc_in[6] = 1500; // Mid-level thrust
    inputs.rc_in[7] = 2000; // Full forward command
    inputs.rc_in[8] = 1500; // Neutral lateral command
    inputs.gyro = {0.0f, 0.0f, 0.0f};
    inputs.pitch_rad = 0.0f;
    inputs.roll_rad = 0.0f;

    // 3. Run logic multiple times to allow PIDs to respond
    TVC_Outputs outputs;
    for (int i = 0; i < 100; ++i) {
        inputs.now_us += 2500; // 400Hz
        outputs = tvc_run_main_logic(inputs, state, tvc_test_config);
    }

    // 4. Assert the expected outputs
    assert_true(outputs.debug_data.pitch_saturated, "Pitch should be saturated");
    // Headroom is 1.0 - 0.9 = 0.1. The output should be clamped to this value.
    assert_equals_float(0.1f, outputs.debug_data.vector_pitch_out, 0.001, "Pitch command should be clamped to headroom");
}

void run_failsafe_test() {
    printf("\n--- Running Test Case: Failsafe Test ---\n");

    // 1. Setup state
    LinearPIDController pitch_rate_pid(tvc_test_config.pitch_rate_low.p, tvc_test_config.pitch_rate_low.i, tvc_test_config.pitch_rate_low.d, tvc_test_config.i_max_pitch_rate);
    LinearPIDController roll_rate_pid(tvc_test_config.roll_rate_low.p, tvc_test_config.roll_rate_low.i, tvc_test_config.roll_rate_low.d, tvc_test_config.i_max_roll_rate);
    LinearPIDController pitch_angle_pid(tvc_test_config.pitch_angle.p, tvc_test_config.pitch_angle.i, tvc_test_config.pitch_angle.d, tvc_test_config.i_max_angle);
    LinearPIDController roll_angle_pid(tvc_test_config.roll_angle.p, tvc_test_config.roll_angle.i, tvc_test_config.roll_angle.d, tvc_test_config.i_max_angle);
    CustomFilter target_pitch_rate_filter(25.0f, 1.0f/400.0f, IIR::OD2);
    CustomFilter target_roll_rate_filter(25.0f, 1.0f/400.0f, IIR::OD2);

    TVC_State state = {
        pitch_rate_pid, roll_rate_pid, pitch_angle_pid, roll_angle_pid,
        target_pitch_rate_filter, target_roll_rate_filter,
        false, false
    };
    state.pitch_angle_pid.reset();
    state.roll_angle_pid.reset();
    state.pitch_rate_pid.reset();
    state.roll_rate_pid.reset();

    // 2. Setup mock inputs
    TVC_Inputs inputs = {};
    inputs.ahrs_healthy = true;
    inputs.in_failsafe = true; // <-- TRIGGER FAILSAFE
    inputs.now_us = 0;
    for (int i = 0; i < 6; i++) {
        inputs.rc_in[i] = 1100;
    }
    inputs.rc_in[6] = 1500;
    inputs.rc_in[7] = 2000; // Active forward command
    inputs.rc_in[8] = 1500;
    inputs.gyro = {0.0f, 0.0f, 0.0f};
    inputs.pitch_rad = 0.0f;
    inputs.roll_rad = 0.0f;

    // 3. Call the core logic function
    TVC_Outputs outputs = tvc_run_main_logic(inputs, state, tvc_test_config);

    // 4. Assert the expected outputs
    assert_equals_float(0.0f, outputs.debug_data.vector_pitch_out, 0.001, "Pitch command should be zero in failsafe");
    assert_equals_float(0.0f, outputs.debug_data.vector_roll_out, 0.001, "Roll command should be zero in failsafe");
    assert_equals_float(1.0f, outputs.debug_data.thrust_factor, 0.001, "Thrust factor should be 1.0 in failsafe");
}

void run_motor_off_test() {
    printf("\n--- Running Test Case: Motor-Off Test ---\n");

    // 1. Setup state
    LinearPIDController pitch_rate_pid(tvc_test_config.pitch_rate_low.p, tvc_test_config.pitch_rate_low.i, tvc_test_config.pitch_rate_low.d, tvc_test_config.i_max_pitch_rate);
    LinearPIDController roll_rate_pid(tvc_test_config.roll_rate_low.p, tvc_test_config.roll_rate_low.i, tvc_test_config.roll_rate_low.d, tvc_test_config.i_max_roll_rate);
    LinearPIDController pitch_angle_pid(tvc_test_config.pitch_angle.p, tvc_test_config.pitch_angle.i, tvc_test_config.pitch_angle.d, tvc_test_config.i_max_angle);
    LinearPIDController roll_angle_pid(tvc_test_config.roll_angle.p, tvc_test_config.roll_angle.i, tvc_test_config.roll_angle.d, tvc_test_config.i_max_angle);
    CustomFilter target_pitch_rate_filter(25.0f, 1.0f/400.0f, IIR::OD2);
    CustomFilter target_roll_rate_filter(25.0f, 1.0f/400.0f, IIR::OD2);

    TVC_State state = {
        pitch_rate_pid, roll_rate_pid, pitch_angle_pid, roll_angle_pid,
        target_pitch_rate_filter, target_roll_rate_filter,
        false, false
    };
    state.pitch_angle_pid.reset();
    state.roll_angle_pid.reset();
    state.pitch_rate_pid.reset();
    state.roll_rate_pid.reset();

    // 2. Setup mock inputs
    TVC_Inputs inputs = {};
    inputs.ahrs_healthy = true;
    inputs.in_failsafe = false;
    inputs.now_us = 0;
    // Set all motor channels to a value below the MOTOR_OFF_THRESHOLD (1063)
    for (int i = 0; i < 6; i++) {
        inputs.rc_in[i] = 1000;
    }
    inputs.rc_in[6] = 1500;
    inputs.rc_in[7] = 2000; // Active forward command
    inputs.rc_in[8] = 1500;
    inputs.gyro = {0.0f, 0.0f, 0.0f};
    inputs.pitch_rad = 0.0f;
    inputs.roll_rad = 0.0f;

    // 3. Call the core logic function
    TVC_Outputs outputs = tvc_run_main_logic(inputs, state, tvc_test_config);

    // 4. Assert the expected outputs
    assert_equals_float(0.0f, outputs.debug_data.vector_pitch_out, 0.001, "Pitch command should be zero when motors are off");
    assert_equals_float(0.0f, outputs.debug_data.vector_roll_out, 0.001, "Roll command should be zero when motors are off");
    assert_equals_float(1.0f, outputs.debug_data.thrust_factor, 0.001, "Thrust factor should be 1.0 when motors are off");
}

void run_helper_function_tests() {
    printf("\n--- Running Test Case: Helper Functions ---\n");

    // Test sbus_pwm_to_float
    assert_equals_float(0.0f, sbus_pwm_to_float(1000, 0.0f, 1.0f), 0.001, "sbus_pwm_to_float: min value");
    assert_equals_float(0.5f, sbus_pwm_to_float(1500, 0.0f, 1.0f), 0.001, "sbus_pwm_to_float: mid value");
    assert_equals_float(1.0f, sbus_pwm_to_float(2000, 0.0f, 1.0f), 0.001, "sbus_pwm_to_float: max value");
    assert_equals_float(-1.0f, sbus_pwm_to_float(1000, -1.0f, 1.0f), 0.001, "sbus_pwm_to_float: min value (bipolar)");
    assert_equals_float(0.0f, sbus_pwm_to_float(1500, -1.0f, 1.0f), 0.001, "sbus_pwm_to_float: mid value (bipolar)");
    assert_equals_float(1.0f, sbus_pwm_to_float(2000, -1.0f, 1.0f), 0.001, "sbus_pwm_to_float: max value (bipolar)");

    // Test float_to_sbus_pwm
    assert_equals_int(1000, float_to_sbus_pwm(0.0f, 0.0f, 1.0f), "float_to_sbus_pwm: min value");
    assert_equals_int(1500, float_to_sbus_pwm(0.5f, 0.0f, 1.0f), "float_to_sbus_pwm: mid value");
    assert_equals_int(2000, float_to_sbus_pwm(1.0f, 0.0f, 1.0f), "float_to_sbus_pwm: max value");
    assert_equals_int(1000, float_to_sbus_pwm(-1.0f, -1.0f, 1.0f), "float_to_sbus_pwm: min value (bipolar)");
    assert_equals_int(1500, float_to_sbus_pwm(0.0f, -1.0f, 1.0f), "float_to_sbus_pwm: mid value (bipolar)");
    assert_equals_int(2000, float_to_sbus_pwm(1.0f, -1.0f, 1.0f), "float_to_sbus_pwm: max value (bipolar)");

    // Test constrain_float
    assert_equals_float(5.0f, constrain_float(5.0f, 0.0f, 10.0f), 0.001, "constrain_float: value in range");
    assert_equals_float(0.0f, constrain_float(-5.0f, 0.0f, 10.0f), 0.001, "constrain_float: value below range");
    assert_equals_float(10.0f, constrain_float(15.0f, 0.0f, 10.0f), 0.001, "constrain_float: value above range");

    // Test degrees
    assert_equals_float(0.0f, degrees(0.0f), 0.001, "degrees: 0 radians");
    assert_equals_float(90.0f, degrees(M_PI / 2.0f), 0.001, "degrees: PI/2 radians");
    assert_equals_float(180.0f, degrees(M_PI), 0.001, "degrees: PI radians");
}

void run_clip_vectors_test() {
    printf("\n--- Running Test Case: clip_vectors_for_saturation ---\n");

    float throttles[NUM_PODS];
    float pitch, roll;
    bool pitch_saturated, roll_saturated;

    // --- Test 1: No Saturation ---
    printf("Sub-case: No Saturation\n");
    for (int i = 0; i < NUM_PODS; i++) throttles[i] = 0.5f; // 50% throttle
    pitch = 0.2f;
    roll = -0.2f;
    clip_vectors_for_saturation(throttles, &pitch, &roll, pitch_saturated, roll_saturated);
    assert_false(pitch_saturated, "No Saturation: pitch_saturated should be false");
    assert_false(roll_saturated, "No Saturation: roll_saturated should be false");
    assert_equals_float(0.2f, pitch, 0.001, "No Saturation: pitch should be unchanged");
    assert_equals_float(-0.2f, roll, 0.001, "No Saturation: roll should be unchanged");

    // --- Test 2: Positive Saturation ---
    printf("Sub-case: Positive Saturation\n");
    throttles[0] = 0.9f; // Max throttle, leaves 0.1 headroom
    throttles[1] = 0.5f;
    pitch = 0.3f; // Exceeds headroom
    roll = 0.05f; // Within headroom
    clip_vectors_for_saturation(throttles, &pitch, &roll, pitch_saturated, roll_saturated);
    assert_true(pitch_saturated, "Positive Saturation: pitch_saturated should be true");
    assert_false(roll_saturated, "Positive Saturation: roll_saturated should be false");
    assert_equals_float(0.1f, pitch, 0.001, "Positive Saturation: pitch should be clamped to 0.1");
    assert_equals_float(0.05f, roll, 0.001, "Positive Saturation: roll should be unchanged");

    // --- Test 3: Negative Saturation ---
    printf("Sub-case: Negative Saturation\n");
    throttles[0] = 0.1f; // Min throttle, leaves 0.1 headroom
    throttles[1] = 0.5f;
    pitch = -0.3f; // Exceeds headroom
    roll = -0.05f; // Within headroom
    clip_vectors_for_saturation(throttles, &pitch, &roll, pitch_saturated, roll_saturated);
    assert_true(pitch_saturated, "Negative Saturation: pitch_saturated should be true");
    assert_false(roll_saturated, "Negative Saturation: roll_saturated should be false");
    assert_equals_float(-0.1f, pitch, 0.001, "Negative Saturation: pitch should be clamped to -0.1");
    assert_equals_float(-0.05f, roll, 0.001, "Negative Saturation: roll should be unchanged");

    // --- Test 4: Asymmetric Saturation ---
    printf("Sub-case: Asymmetric Saturation\n");
    throttles[0] = 0.9f;  // Positive headroom = 0.1
    throttles[1] = 0.2f;  // Negative headroom = 0.2
    // Available headroom is min(0.1, 0.2) = 0.1
    pitch = 0.15f;
    roll = -0.15f;
    clip_vectors_for_saturation(throttles, &pitch, &roll, pitch_saturated, roll_saturated);
    assert_true(pitch_saturated, "Asymmetric Saturation: pitch_saturated should be true");
    assert_true(roll_saturated, "Asymmetric Saturation: roll_saturated should be true");
    assert_equals_float(0.1f, pitch, 0.001, "Asymmetric Saturation: pitch should be clamped to 0.1");
    assert_equals_float(-0.1f, roll, 0.001, "Asymmetric Saturation: roll should be clamped to -0.1");
}

void run_integration_simulation_test() {
    printf("\n--- Running Test Case: Integration Simulation ---\n");

    // 1. Setup state
    LinearPIDController pitch_rate_pid(tvc_test_config.pitch_rate_low.p, tvc_test_config.pitch_rate_low.i, tvc_test_config.pitch_rate_low.d, tvc_test_config.i_max_pitch_rate);
    LinearPIDController roll_rate_pid(tvc_test_config.roll_rate_low.p, tvc_test_config.roll_rate_low.i, tvc_test_config.roll_rate_low.d, tvc_test_config.i_max_roll_rate);
    LinearPIDController pitch_angle_pid(tvc_test_config.pitch_angle.p, tvc_test_config.pitch_angle.i, tvc_test_config.pitch_angle.d, tvc_test_config.i_max_angle);
    LinearPIDController roll_angle_pid(tvc_test_config.roll_angle.p, tvc_test_config.roll_angle.i, tvc_test_config.roll_angle.d, tvc_test_config.i_max_angle);
    CustomFilter target_pitch_rate_filter(25.0f, 1.0f/400.0f, IIR::OD2);
    CustomFilter target_roll_rate_filter(25.0f, 1.0f/400.0f, IIR::OD2);

    TVC_State state = {
        pitch_rate_pid, roll_rate_pid, pitch_angle_pid, roll_angle_pid,
        target_pitch_rate_filter, target_roll_rate_filter,
        false, false
    };
    state.pitch_angle_pid.reset();
    state.roll_angle_pid.reset();
    state.pitch_rate_pid.reset();
    state.roll_rate_pid.reset();

    // 2. Setup initial inputs
    TVC_Inputs inputs = {};
    inputs.ahrs_healthy = true;
    inputs.in_failsafe = false;
    inputs.now_us = 0;
    for (int i = 0; i < 6; i++) {
        inputs.rc_in[i] = 1100;
    }
    inputs.rc_in[6] = 1500; // Mid-level thrust
    inputs.gyro = {0.0f, 0.0f, 0.0f};
    inputs.pitch_rad = 0.0f;
    inputs.roll_rad = 0.0f;

    const int num_steps = 400; // 1 second simulation
    const float dt = 1.0f / 400.0f;

    // 3. Run simulation loop
    for (int i = 0; i < num_steps; ++i) {
        inputs.now_us += (uint32_t)(dt * 1e6);

        // Generate a sinusoidal stick input for forward command
        float sine_wave = sinf(2.0f * M_PI * i / num_steps);
        inputs.rc_in[7] = float_to_sbus_pwm(sine_wave, -1.0f, 1.0f);
        inputs.rc_in[8] = 1500; // Neutral lateral

        TVC_Outputs outputs = tvc_run_main_logic(inputs, state, tvc_test_config);

        // --- Sanity Checks ---
        assert_greater_than_or_equal(1.0, outputs.debug_data.thrust_factor, "Sim: Thrust factor should be >= 1.0");
        assert_equals_float(0.0, outputs.debug_data.vector_roll_out, 0.1, "Sim: Roll output should be near zero");

        // --- Simple Physics Simulation ---
        // Update gyro based on vector output (highly simplified)
        inputs.gyro.y += outputs.debug_data.vector_pitch_out * 500.0f * dt; // Simplified rotational acceleration
        inputs.gyro.x += outputs.debug_data.vector_roll_out * 500.0f * dt;
        // Integrate gyro to get attitude
        inputs.pitch_rad += inputs.gyro.y * dt;
        inputs.roll_rad += inputs.gyro.x * dt;
        // Add some damping
        inputs.gyro.y *= 0.90f;
        inputs.gyro.x *= 0.90f;
    }

    printf("Simulation finished. Final checks...\n");
    // After the sine wave completes, the system should return to near-zero.
    assert_equals_float(0.0f, inputs.pitch_rad, 0.15, "Final pitch should be near zero");
    assert_equals_float(0.0f, inputs.gyro.y, 0.1, "Final pitch rate should be near zero");
}

void run_thrust_compensation_test() {
    printf("\n--- Running Test Case: Thrust Compensation ---\n");

    // 1. Setup state (don't need PIDs for this)
    LinearPIDController pitch_rate_pid(0,0,0,0);
    LinearPIDController roll_rate_pid(0,0,0,0);
    LinearPIDController pitch_angle_pid(0,0,0,0);
    LinearPIDController roll_angle_pid(0,0,0,0);
    CustomFilter target_pitch_rate_filter(25.0f, 1.0f/400.0f, IIR::OD2);
    CustomFilter target_roll_rate_filter(25.0f, 1.0f/400.0f, IIR::OD2);
    TVC_State state = { pitch_rate_pid, roll_rate_pid, pitch_angle_pid, roll_angle_pid, target_pitch_rate_filter, target_roll_rate_filter, false, false };

    // 2. Setup mock inputs
    TVC_Inputs inputs = {};
    inputs.ahrs_healthy = true;
    inputs.in_failsafe = false;
    for (int i = 0; i < 6; i++) inputs.rc_in[i] = 1100;
    inputs.rc_in[6] = 1500; // Mid-level thrust (0.5)

    // 3. Iterate through a range of commands
    for (int i = 0; i <= 10; ++i) {
        float forward_cmd = (float)i / 10.0f; // 0.0 to 1.0
        for (int j = 0; j <= 10; ++j) {
            float lateral_cmd = (float)j / 10.0f; // 0.0 to 1.0

            inputs.rc_in[7] = float_to_sbus_pwm(forward_cmd, -1.0f, 1.0f);
            inputs.rc_in[8] = float_to_sbus_pwm(lateral_cmd, -1.0f, 1.0f);

            TVC_Outputs outputs = tvc_run_main_logic(inputs, state, tvc_test_config);

            // Calculate expected thrust factor
            float thrust_cmd = 0.5f;
            float shaped_forward_cmd = forward_cmd;
            float shaped_lateral_cmd = lateral_cmd;

            // Replicate the input shaping from the main logic
            const float MAX_TARGET_ANGLE_DEG_TEST = 45.0f;
            const float max_tan_angle = tanf(MAX_TARGET_ANGLE_DEG_TEST * M_PI / 180.0);
            float max_horizontal_magnitude = thrust_cmd * max_tan_angle;
            float current_horizontal_magnitude = sqrtf(powf(shaped_forward_cmd, 2) + powf(shaped_lateral_cmd, 2));
            if (current_horizontal_magnitude > max_horizontal_magnitude) {
                if (current_horizontal_magnitude > 0.0f) {
                    float scale_factor = max_horizontal_magnitude / current_horizontal_magnitude;
                    shaped_forward_cmd *= scale_factor;
                    shaped_lateral_cmd *= scale_factor;
                }
            }

            float target_pitch_rad = atan2f(shaped_forward_cmd, thrust_cmd);
            float down_and_forward_mag = sqrtf(powf(shaped_forward_cmd, 2) + powf(thrust_cmd, 2));
            float target_roll_rad = atan2f(shaped_lateral_cmd, down_and_forward_mag);
            
            float expected_thrust_factor = 1.0f / (cosf(target_pitch_rad) * cosf(target_roll_rad));
            expected_thrust_factor = constrain_float(expected_thrust_factor, 1.0f, 1.5f);

            char msg[100];
            sprintf(msg, "Thrust factor check for fwd=%.1f, lat=%.1f, expected=%.1f", forward_cmd, lateral_cmd, expected_thrust_factor);
            assert_equals_float(expected_thrust_factor, outputs.debug_data.thrust_factor, 0.001, msg);
        }
    }
}


int main() {
    printf("--- Starting TVC Logic Unit Test ---\n");
    run_zero_input_test();
    run_full_forward_test();
    run_full_lateral_test();
    run_saturation_test();
    run_failsafe_test();
    run_motor_off_test();
    run_helper_function_tests();
    run_clip_vectors_test();
    run_integration_simulation_test();
    run_thrust_compensation_test();
    printf("\n--- TVC Logic Unit Test Finished ---\n");
    return 0;
}
