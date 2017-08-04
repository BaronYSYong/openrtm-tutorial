# Step 5: Use DataPort with Original Data Type

Describe IDL file to define your data type and load your IDL file in your RTC builder.

## Definition (IDL file)

Description rules of IDL file is a bit complicated to explain in this website. See CORBA books or some other documentation around IDL file.

```
// TestIDL.idl

module ssr {

  struct TestStruct1 {
    long value1;
    float value2;
  };

  typedef sequence TestSequence1;
  
  struct TestStruct2 {
    TestStruct1 header;
    TestSequence1 data;
  };
};
```

## Setting of Loading IDL file

Open Eclipse and open property dialog. In OSX, Eclipse > Preference.

Then, select RTC Builder in the left side menu of the dialog, and you can see the display like below:

![](image/22.png)

Select the folder that includes your IDL file.
Reboot Eclipse.

## Build RTC with your original data type
You can build the skeleton code in the ordinary 
.
![](image/23.png)