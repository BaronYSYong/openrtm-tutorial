# Tutorial 3: Activate / Deactivate RTC

## Launch RT System Editor
Launch "All-In-One eclipse" and select "RT System Editor" perspective.
(Menu >> Window >> Perspective >> RT System Editor)

## Connect to Name Service
Please connect Naming Service if your RT System Editor do not indicated executing Naming Service (you might see "localhost").
Press "Add Name Server" button and input your Name Server's IP Address (usually, localhost).

![](image/9.png) 

## Visualize your RTC
Open "RT System Editor view" by pressing the following button.
Then, open your Name Server's tree, and drag & drop the RTC to the opened editor panel.
![](image/10.png) 

## Activate RTC
Right click your RTC and select "Activate" menu from the drop-down menu.

![](image/11.png) 

Your RTC will become "GREEN" from "BLUE". The GREEN colored RTC means the RTC is in "ACTIVE" state.
The BLUE RTCs are in "INACTIVE" state.

![](image/12.png) 

If you watch RED RTCs, they are "ERROR" state.

The RT System Builder can send the trigger to change the RTC's state machine.

When your RTC changes to "ACTIVE" state from "INACTIVE" state, the "onActivated" function is called, so the RTC's console will output some messages in our example.

In ACTIVE state, onExecute function is periodically called.
You will see the following message in your console window of the RTC.

![](image/13.png) 

If you "deactivate" your RTC, the "onDeactivated" will be called on the contrary.

![](image/14.png) 

The RTC's parameters (ex., onExecute's period) can be customized by rtc.conf file.
