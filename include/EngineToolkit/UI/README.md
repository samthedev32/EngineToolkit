# UI

This is a UI Builder library highly inspired by [Compose](https://www.jetbrains.com/lp/compose-multiplatform/)
It aims to be efficient, flexible and easy-to-use

## Modifier
> TODO

## Layout Prototype
> TODO

Core Elements:
- Box (Container)
- Card (Visual)

Element Inheritance
```mermaid
graph LR;
%% Container Types
    Box --> Row;
    Box --> Column;
    Box --> Drawer;

    Row --> RowList;
    Column --> ColumnList;

%% Interactive Types
    Card --> Button;
    Card --> Switch;
    Card --> Joystick;
    Card --> TextField;

    Switch --> CheckBox;
    CheckBox --> RadioButton;

    Button --> Slider;
    Button --> Spinner;

%% Visual Types
    Card --> Image;
    Card --> Icon;
    Card --> Video;
    Card --> Text;

    Slider --> ProgressBar;
    Spinner --> ProgressCircle;
```

## Layout
> TODO