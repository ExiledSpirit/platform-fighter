# rollback

Rollback module contains the systems that enable:
- saving past simulation states
- restoring old frames
- re-simulating forward when corrected inputs arrive (later, for network stuff)
- replay by input log (later, for replay stuff)

Rule:
- rollback should not know about menus/screens.
- it operates only on SimState + per-frame inputs.
