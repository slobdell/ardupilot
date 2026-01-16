# sudo apt-get install gcc-arm-none-eabi make
# sudo apt-get install python3-empy
# sudo apt-get install python3-future
# sudo apt-get install python3-intelhex  # necessary for building .hex bootloader
# git submodule update --init --recursive
BOARD=FlywooF745
BOARD=CubeOrangePlus
BOARD=mRoControlZeroH7
BOARD=FlywooF745
BOARD=SkystarsH7HD
BOARD=MatekH743
BOARD=MicoAir743
echo "building for $BOARD"
# ./waf configure --board $BOARD --debug --disable-scripting
#./waf configure --board $BOARD
#./waf distclean
./waf configure --board $BOARD
./waf plane
cp ./build/$BOARD/bin/arduplane.apj ~/Desktop/
cp ./build/$BOARD/bin/arduplane_with_bl.hex ~/Desktop/
cp ./build/$BOARD/bin/arduplane_with_bl.hex ./arduplane_with_bl.hex
cp ./build/$BOARD/bin/arduplane ~/Desktop/arduplane.elf
cp ./build/$BOARD/bin/arduplane ./arduplane.elf
# openocd -f interface/stlink.cfg -f target/stm32h7x.cfg -c "program arduplane.elf verify reset exit"
#
# FOR TESTING
# ./waf configure --board sitl
# ./waf tests
# cd tests/custom_main_test; make; ./tvc_test
