
# JSON File Management System

**Course**: Object-Oriented Programming  
**Program**: Software Engineering, Faculty of Mathematics and Informatics (FMI)  
**Year**: 2023/2024  

This project implements a system for working with JSON files. It reads, manipulates, and performs operations on JSON data structures. 
**Note**: The use of libraries for handling JSON is not allowed in this project. The goal is to construct an appropriate tree-like representation of the data in memory and implement operations on it.

## Functionalities

When a valid JSON file is provided, the program reads it and stores the data in a memory structure. The following operations are supported, in addition to common commands like `open`, `close`, `save`, `save as`, `help`, and `exit`:

### 1. **validate**
- Checks if the opened file is valid according to the JSON syntax.
- If there are any issues, the program provides a clear description of what and where the problem is so the user can fix it.

### 2. **print**
- Outputs the content of the JSON object in a human-readable format.

### 3. **search `<key>`**
- Checks if the object contains data under the provided key, which may exist at any nesting level.
- If found, returns an array of all such occurrences, with each represented as a JSON object.
- **Bonus**: Allows searching by regular expression (e.g., searching for "person-*" finds all keys that start with "person-").

### 4. **set `<path>` `<string>`**
- Replaces the value of a specific element identified by its full path with the provided string, according to the JSON syntax.
- If the element doesn't exist or the string is invalid, an error is returned.

### 5. **create `<path>` `<string>`**
- Adds a new element at the specified path with the given value, according to the JSON syntax.
- If the element already exists, the program raises an error. It also supports recursive creation of the entire path if needed.
- If the string is invalid, an error message is shown.

### 6. **delete `<path>`**
- Deletes the element at the specified path if it exists, or returns an error for an invalid path.

### 7. **move `<from>` `<to>`**
- Moves all elements from one path to another.

### 8. **save `[<path>]`**
- Saves the object at the specified path to the current file.
- If no path is provided, the entire object in memory is saved.

### 9. **saveas `<file>` `[<path>]`**
- Saves the object at the specified path to a new file.
- If no path is provided, the entire object in memory is saved.

---

## Example

Let's assume we have the following `organisation.json` file describing an organization:

```json
{
   "name":"ACME Software Co.",
   "type":"Software Development Company",
   "offices": [
               {
                   "name":"Headquarters",
                   "address":"Sofia"
               },
               {
                   "name":"Front Office",
                   "address":"New York City"
               }
              ],
   "members":[
               {   
                   "id" : "0",
                   "name" : "John Smith",
                   "birthdate" : "1980-01-01"
               },
               {
                   "id" : "1",
                   "name" : "Jane Smith",
                   "birthdate" : "1981-02-02"
               },
               {
                   "id" : "2",
                   "name" : "John Doe",
                   "birthdate" : "1982-03-03"
               }
           ],
   "management":{
                   "directorId":"0",
                   "presidentId":"1"
                }
}
```

### Example Commands and Results

#### 1. **Search Command**

```bash
search "name"
```

**Output**:
```json
[
   "ACME Software Co.",
   "Headquarters",
   "Front Office",
   "John Smith",
   "Jane Smith",
   "John Doe"
]
```

#### 2. **Set Command**

```bash
set "management/directorId" "2"
```

**Result**:
```json
"management":{
   "directorId":"2",
   "presidentId":"1"
}
```

---

## Constraints
- The program should not support newline characters, quotes, or special symbols in string constants.
- Special care must be taken to handle and validate JSON syntax errors and report them clearly to the user.

