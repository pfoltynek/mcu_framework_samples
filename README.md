# mcu_framework_samples

Examples that demonstrate the benefits of the [mcu_framework](https://github.com/pfoltynek/mcu_framework), which implements SOLID principles and design patterns on microcontrollers. The article describing the individual examples is available at DOI: [10.3390/s24237803](https://www.mdpi.com/1424-8220/24/23/7803)

# Instructions for setting up the NATIVE environment in [JetBrains CLion](https://www.jetbrains.com/clion/)

To run the native platform in PlatformIO, you need to set the paths in the system PATH variable.

**Setting system PATH variables**:
- Open "System Settings" and go to "System Variables".
- Add the following paths to the PATH variable:

```
    %USERPROFILE%\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin
    %USERPROFILE%\AppData\Local\Programs\CLion\bin\mingw\bin
    %USERPROFILE%\AppData\Local\Programs\CLion\bin\gdb\win\x64\bin
```