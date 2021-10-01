# Motion-Detection-w-Audio

The RCWL-0516 was obviosly designed to operate a security light.  Any detected motion triggers a digital output for several seconds and then resets.  Provision is made for a photocel (not included) to prevent operation during daylight.

Examination of the signals on various pins located a heafy analog signal on pin-12 of the IC.  Some simple mods to the board make this signal availble at an unused pin on the module.

By processing (just a dozen or so lines of code), it is possible to make sounds proportional to the motion detected.

What you do from here is up to you.

Luhan Monat
