# input

Input contains everything related to **reading controls** and converting them into **high-level/ abstraction actions**.

Goal:
- Screens and gameplay should not care about raw keys/buttons, this module should handle it and abstract into actions
- They should react to Actions (`UI_Confirm`, `UI_Back`, `MoveLeft`, `Jump`, Etc.)

Typical pipeline:
raylib polling (read keyboard/ gamepad inputs) -> InputSystem (translate into actions) -> InputRouter (emit those actions) -> ActionEvent -> EventBus -> active Screen (listen to those actions and thus perform something).
