---
alias_target: FS_GCS_ENABLE
default_value: GCS_FAILSAFE_OFF
description: 'Enable ground control station telemetry failsafe. Failsafe will trigger
  after FS_LONG_TIMEOUT seconds of no MAVLink heartbeat messages. There are three
  possible enabled settings. Setting FS_GCS_ENABL to 1 means that GCS failsafe will
  be triggered when the aircraft has not received a MAVLink HEARTBEAT message. Setting
  FS_GCS_ENABL to 2 means that GCS failsafe will be triggered on either a loss of
  HEARTBEAT messages, or a RADIO_STATUS message from a MAVLink enabled 3DR radio indicating
  that the ground station is not receiving status updates from the aircraft, which
  is indicated by the RADIO_STATUS.remrssi field being zero (this may happen if you
  have a one way link due to asymmetric noise on the ground station and aircraft radios).Setting
  FS_GCS_ENABL to 3 means that GCS failsafe will be triggered by Heartbeat(like option
  one), but only in AUTO mode. WARNING: Enabling this option opens up the possibility
  of your plane going into failsafe mode and running the motor on the ground it it
  loses contact with your ground station. If this option is enabled on an electric
  plane then you should enable ARMING_REQUIRED.'
display_name: GCS failsafe enable
group: Uncategorized
investigation_status: alias
layout: parameter
name: FS_GCS_ENABL
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp#L484
units: ''
visual_asset_id: null
---

# GCS failsafe enable

**Note:** This parameter functions identically to [FS_GCS_ENABLE](../FS/FS_GCS_ENABLE.html).
