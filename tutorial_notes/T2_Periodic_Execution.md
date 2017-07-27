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

