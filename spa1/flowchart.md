flowchart TD
    A[accept input from file]
    A --> B[read line] -->
    I{does intake exceed 1mL?}
    -->|yes| Y[log that intake exceeds outtake]--> N
    I --> |no| N[update fluid differential]
    --> D{more input?}
    D -->|yes| B
    D -->|no| C[output final fluid differential]
