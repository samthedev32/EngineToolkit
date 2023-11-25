```mermaid
graph LR;
Container Types
    Box --> Row;
    Box --> Column;
    Box --> Drawer;

    Row-->RowList;
    Column-->ColumnList;

Visual Types
    Card-->Button;
    Card-->Switch;
    Card-->Joystick;
    Button-->CheckBox;
    CheckBox-->RadioButton;
    Card-->TextField;

    Button-->Slider;
    Button-->Spinner;

    Card-->Image;
    Card-->Icon;
    Card-->Video;
    Card-->Text;

    Slider-->ProgressBar;
    Spinner-->ProgressCircle;
```