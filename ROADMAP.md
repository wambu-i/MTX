#### First time user flow

---

- [ ] Creation of config file.  
- [ ] On the fly sorting.  
- [ ] Write sorting to config file.  
- [ ] Update config file based on current usage.


#### Consequent user flow

---

- [ ] Read config file for previously sorted files.  
- [ ] Display according to read data.  
- [ ] Update after current usage.

#### Shared sorting library.

---

Public end point will be the `Sorting` class.

The `Sorting` class will interface with the `Config` and `Directories` classes to return a vector of sorted directories.

The `Sorting` class will:  
   - [ ] Get a path from the GUI.
   - [ ] Check if the path exists in the config file.
   - [ ] If the path exists, get the sorted entries, and return a vector of them.
   - [ ] If the path does not exist, sort on the fly and create an entry in the config file for it.
   - [ ] Update after end of current usage.


Example config file:

```
   {
       "/home/wambui/": {
           "Monday": [("Downloads", 5), ("Books", 3)],
           "Tuesday": [("Pictures", 7), ("Videos", 1)]
       }
   }
```