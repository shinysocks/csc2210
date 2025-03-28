## compiling
first compile raylib following the instructions below:
* [Compiling for GNU Linux](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux)
* [Compiling For Windows](https://github.com/raysan5/raylib/wiki/Working-on-Windows)

once raylib has been installed on the target system, the project can be run:
```
make
```

## uml
```mermaid
classDiagram

class Window {
    -WIDTH
    -HEIGHT
    -SPACE_TEXT
    -DOT
    -DASH
    -INVALID_CODE
    -is_dot
    -countdown_timer
    -decoded_char
    -message

    +Window()
    +render()
    +is_symbol_dot(bool)
    +set_countdown(int, char)
    +set_message(char*)
}

class Node {
    +data
    +left
    +right
    +Node(E)
    +Node(E, Node, Node)
}

class MorseTree {
    -root
    +add(E, string)
    -add(E, string, Node)
    +decode(string)
    -decode(string, node)
}
```
---

## Program Flow
```mermaid
flowchart TD

sp{waiting for input} -- space pressed --> ss[start stopwatch + play tone]
ss -- space released --> sr[record time + stop tone] --> td{time is dot?} -- true --> ed[encode dot] --> D
td -- false --> eD[encode dash] --> D
D[display encoded symbol]
D --> E{exit countdown} -- space pressed -->ss
E -- timeout --> P[play back phrase and output letter by letter]
P --> sp
```


