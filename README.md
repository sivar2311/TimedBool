# TimedBool
A boolean that inverts its value after an expiration time.

To start the timer, the following conditions must be met:
- An expiration time must be set ([during declaration](#declaration-with-expiration-time) or by calling [`setExpiration`](#setexpiration)).
- A value must be assigned ([during declaration](#declaration-with-expiration-time-and-value), by calling [`setValue`](#setvalue) or by using the [assignment opertor =](#assignment-operator)).

# Declaration

## Default declaration
```C++
TimedBool b;
```
`b` is initialized with the value `false` and no expiration time. 

The timer ist not startet. 

## Declaration with expiration time
```C++
TimedBool b(2000);
```
`b` is initialized with the value `false` and an expiration time of 2000 ms. 

The timer ist not startet. 

## Declaration with expiration time and value
```C++
TimedBool b(2000, true);
```
`b` is initialized to `true`, with an expiration time of 2000 milliseconds. 

The timer is started and after the expiration time has elapsed the value is changed to `false`.

This can be used to assing a value and an expiration time in a single line of code:
```C++
  b = TimedBool(2000, true);
```
Short version:
```C++
  b = {2000, true};
```

# Methods

## `setExpiration`
```C++
void setExpiration(unsigned long expiration);
```
Set or changes the expiration time (in milliseconds).

Setting the expiration time does not start the timer.

## `getExpiration`
```C++
unsigned long getExpiration();
```
Returns the expiration time.

## `setValue`
```C++
void setValue(bool value);
```
Set the value.

Setting a value starts the timer if an expiration time has been set before.

When the expiration time is elapsed, the value is inverted.

## `getValue`
```C++
bool getValue();
```
Returns the current value.

# Operators
## `Conversion operator bool`
```C++
operator bool();
```
This allows to use a `TimedBool` like a standard boolean:

```C++
  if (b == true) ...
  if (b == false) ...
```
## `Assignment operator`
```C++
TimedBool& operator=();
```
This allows a `TimedBool` to be assigned a value (`true` or `false`) like a standard boolean.
```C++
  b = true; 
  b = false;
```

Setting a value starts the timer if an expiration time has been set before.

When the expiration time is elapsed, the value is inverted.

# Installation (PlatformIO)

`platformio.ini`

```
lib_deps = 
  https://github.com/sivar2311/TimedBool.git