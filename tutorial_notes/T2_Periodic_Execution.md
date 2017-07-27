# Tutorial 2: Periodic Execution of RTC (C++)

## Override Callback Functions
In the MyFirstRTC.cpp, you can find lots of function declaration (but commented out).
If you edit the "activity tab" in RTC builder, the selected callback function will be uncommented.

In the previous step, you would have activated the following three functions:
1. onActivated
2. onDeactivated
3. onExecute

Example:
```
RTC::ReturnCode_t MyFirstRTC::onActivated(RTC::UniqueId ec_id)
{
  std::cout<<"onActivated"<<std::endl;
  return RTC::RTC_OK;
}


RTC::ReturnCode_t MyFirstRTC::onDeactivated(RTC::UniqueId ec_id)
{
  std::cout<<"onDeactivated"<<std::endl;
  return RTC::RTC_OK;
}


RTC::ReturnCode_t MyFirstRTC::onExecute(RTC::UniqueId ec_id)
{
  std::cout<<"onExecute"<<std::endl;
  return RTC::RTC_OK;
}
```

### Build
```
$ cd path-to-workspace/MyFirstRTC/
$ mkdir build
$ cd build
$ cmake ..
$ make
```

### Launch RTC
#### Start Name Service
```
$ sudo service omniNames stop
$ rtm-naming

Starting omniNames for the first time.
Wrote initial log file.
Read log file successfully.
Root context is IOR:010000002b00000049444c3a6f6d672e6f72672f436f734e616d696e672f4e616d696e67436f6e746578744578743a312e30000001000000000000006c000000010102000a00000031302e302e322e313500f90a0b0000004e616d6553657276696365000300000000000000080000000100000000545441010000001c00000001000000010001000100000001000105090101000100000009010100035454410800000012b17959010013a5
Checkpointing Phase 1: Prepare.
Checkpointing Phase 2: Commit.
Checkpointing completed.
omniNames properly started
```

#### RTC
```
$ cd path-to-workspace/MyFirstRTC/build/src
$ ./MyFirstRTCComp
```
