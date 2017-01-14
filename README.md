#Minitel library for Arduino

This library provides a way to create screens for the [Minitel](https://en.wikipedia.org/wiki/Minitel) without having to dig into the complexity of the system.

##Schematic

A DIN 45º plug is required to plug the Arduino to the Minitel

![Alt text](/images/DIN.png?raw=true "Schematic")

##External libraries

This library is using SoftwareSerial, please install it prior to compiling any Minitel sketch.

##Constructor

Default constructor, using Arduino PINs 6 and 7 for TX/RX

```
#include <SoftwareSerial.h>
#include <Minitel.h>
Minitel minitel;

void setup() {
}
...
```

Custom constructor using other Arduino PINs for TX/RX

```
#include <SoftwareSerial.h>
#include <Minitel.h>
Minitel minitel(10, 11);

void setup() {
}
...
```

You can set serial speed in constructor

```
#include <SoftwareSerial.h>
#include <Minitel.h>
Minitel minitel(4800); // for 4800 bauds. See setSpeed method for more informations

void setup() {
}
...
```
Or with custom PINs

```
#include <SoftwareSerial.h>
#include <Minitel.h>
Minitel minitel(10, 11, 4800); // for 4800 bauds. See setSpeed method for more informations

void setup() {
}
...
```
##Graphic and Text modes

Here is how you can switch between text and graphic mode 

```
minitel.graphicMode();
minitel.textMode();
```

## Cursor positionning

### Moving the cursor to a certain position

Move the cursor to a certain location

```
minitel.moveCursorTo(HOME);
```

Other possible positions are :

#### Cursor related
- HOME : beginning of the current line
- LINE_END : end of the current line

#### Screen related
- TOP_LEFT : top left of the screen
- TOP_RIGHT : top right of the screen
- BOTTOM_LEFT : bottom left of the screen
- BOTTOM_RIGHT : bottom right of the screen
- CENTER : center of the screen

### Moving the cursor to an XY position

Move the cursor to a given position (x,y), anywhere in the screen

x has a max of 40

y has a max of 24

```
minitel.moveCursorTo(10, 2);
```

### Moving the cursor in a certain direction

Move the cursor based on its current position

You can specify how many times you the cursor should be moved this direction

```
minitel.moveCursor(UP);
minitel.moveCursor(RIGHT, 10);
```
Available directions :
- LEFT
- RIGHT
- DOWN
- UP

### Show/hide the cursor

You can show (white square) or hide the cursor

```
minitel.cursor();
minitel.noCursor();
```

## Clear the screen

Clear all characters and move the cursor to the top-left of the screen

```
minitel.clearScreen();
```

## Sound

You can trigger a bip by calling this function with a duration (in milliseconds)

The duration has to be greater than 200ms

```
minitel.bip(1000);
```

## Colors

You can change the text or graphics color and background color

```
minitel.bgColor(WHITE);
minitel.textColor(BLUE);
```

Available colors are (grayscale on most Minitels)

- BLACK
- RED
- GREEN
- YELLOW
- MAGENTA
- BLUE
- CYAN
- WHITE

You can reset colors to their default values (white characters, black background) using 

```
minitel.useDefaultColors();
```

## Display text

### Single characters

Write a single char at the cursor position or at a given position (x,y)

Return boolean (true/false) depending if the character is supported on Minitels

```
minitel.textChar('c');
minitel.textChar('z', 1, 1);
```

### Special characters

The Minitel's special characters can be typed by using the corresponding constants

```
minitel.specialChar(SPE_CHAR_DEGREE);
minitel.specialChar(SPE_CHAR_DEGREE, 2, 10);
```

Available special characters are :
- SPE_CHAR_POUND
- SPE_CHAR_DOLLAR
- SPE_CHAR_HASHTAG
- SPE_CHAR_ARROW_LEFT
- SPE_CHAR_ARROW_UP
- SPE_CHAR_ARROW_RIGHT
- SPE_CHAR_ARROW_DOWN
- SPE_CHAR_DEGREE
- SPE_CHAR_MINUS_PLUS
- SPE_CHAR_DIVIDE
- SPE_CHAR_1_4
- SPE_CHAR_1_2
- SPE_CHAR_3_4
- SPE_CHAR_GRAVE (needs a supported vowel right after)
- SPE_CHAR_ACUTE (needs a supported vowel right after)
- SPE_CHAR_CIRCUMFLEX (needs a supported vowel right after)
- SPE_CHAR_UMLAUT (needs a supported vowel right after)
- SPE_CHAR_CEDIL 
- SPE_CHAR_UPPER_OE
- SPE_CHAR_LOWER_OE
- SPE_CHAR_BETA


### Text

Write a text at the cursor position or at the given position (x,y)

Text orientation can be horizontal (default) or vertical

```
minitel.text("Hello France");
minitel.text("Hello France", 2, 10);
minitel.text("Hello France", VERTICAL);
minitel.text("Hello France", 1, 1, VERTICAL);
```

Orientation can be set using
- HORIZONTAL
- VERTICAL

## Text size

Text size can be set using
```
minitel.charSize(SIZE_DOUBLE);
```

Other options are
- SIZE_NORMAL
- SIZE_DOUBLE_HEIGHT
- SIZE_DOUBLE_WIDTH
- SIZE_DOUBLE


## Graphic characters

When in graphic Mode, the Minitel can display graphic characters.

You can display a graphic char at the cursor position or at a given position as follow:

```
minitel.graphic("010101");
minitel.graphic("100110", 10, 10);
```

Graphic characters are 2 columns by 3 rows.

The string content is split from top to bottom, left to right to fill the 2x3 pseudo-pixel grid. 

The string has to be exactly 6 characters.

Zeros will be filled with the current background color and other values with the current foreground color.

Some examples:

![Alt text](/images/GraphicChar.jpg?raw=true "Graphic character")


## Repeat

One can repeat a single character or graphic several times

```
minitel.textChar('X');
minitel.repeat(7);
```

## Blink

You can make a text blink like this

```
minitel.blink();
minitel.text("Blinking text");
minitel.noBlink();
```

noBlink(); allows to switch back to the default display.

## Pixelated effect 

You can enable/disable a pixelated effect as follow

```
minitel.pixelate();
minitel.noPixelate();
```


## Prefefined drawing functions

### Rectangle

Draw a rectangle using  a given character

Arguments are:
- character
- top left x position
- top left y position
- rectangle width
- rectangle height

```
minitel.rect('X', 1, 1, 20, 20);
```

Draw a rectangle using  a given character, provided as a byte

Arguments are:
- byte 
- top left x position
- top left y position
- rectangle width
- rectangle height

```
minitel.rect(92, 10, 10, 5, 5);
```

### Spiral

Draw a spiral

Arguments are:
- byte 
- center x position
- center y position
- size

```
minitel.spiral(int x, int y, int siz, int c);
```

## Keyboard input

Refer to the MinitelAsKeyboard example for more details

WARNINGS
- It doesn't seem to be working perfectly when you update display in the meantime
- Some keys can't be captured (ie: direction keys)
- The keyboard may enter in sleep mode after some time, meaning there will be some delay when typing the first key after it went to sleep

Another option is to hack the keyboard using a MPC23017 chip and get the input directly.
I'll link to a tutorial and post samples when ready.

### Read and decode the input and then store value(s)

minitel.readKey();

### Check if a key was pressed

boolean pressed = minitel.keyTyped();

### Check which kind of key was pressed (returns a boolean)

```
minitel.isMenuKey();
minitel.isSpecialCharacterKey();
minitel.isCharacterKey();
minitel.accentKeyStored();
```

### Get the key

```
int menu = minitel.getMenuKey(); // Can be checked against the menu key constants
int specialChar = minitel.getSpecialCharacterKey(); // Can be checked agains the special characters constants
char character = minitel.getCharacterKey(); // If 
int accent = minitel.getAccentKey(); // In addition to checking if a character and in case of a lowercase vowel
```


## Set serial speed

Enable you to change the serial speed

```
setSpeed(4800);
```

You can use : 300, 1200, 4800 or 9600 bauds (9600 bauds works only with Minitel 2)

# Undocumented

Here is a list of undocumented functions:

Most of them don't seem to work on the most common Minitel models 

```
minitel.incrustation();
minitel.noIncrustation();

minitel.lineMask();
minitel.noLineMask();
                    
minitel.standardVideo();
minitel.invertVideo();
minitel.transparentVideo();
```

# Advanced



## Speed considerations

When writing several times the same character consecutively, calling the repeat(); function will allow to display it much faster.


## Serial print

If you intend to use the Minitel commands directly (in this case, refer to the device's technical documentation) you can send them directly to the terminal using 

```
minitel.serialprint7(86);
```


## Text

You can get the byte corresponding to a given character by using the following function

```
byte b = minitel.getCharByte('c');
```

This byte can then be used to print a character directly by using 

```
minitel.serialprint7(b);
```

