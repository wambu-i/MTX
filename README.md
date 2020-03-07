MTX is a file explorer that sorts folders and files according to the day that they are most frequently accessed.
This is especially useful for working on a scheduled timetable.

MTX is written using C++ and QT5.

To Do.
- [ ] GUI
    - [ ] Menus
        - [x] File Menu
        - [x] Edit Menu
        - [x] About
    - [ ] Filesystem Views
        - [ ] Directory view
        - [ ] File view
- [ ] Backend
    - [x] Create config file
    - [x] Get file info using `stat`.
    - [ ] Sort files according to last accessed time.
    - [ ] Update config file on each use.
