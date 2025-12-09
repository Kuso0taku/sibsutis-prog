# Usage

### Installation
just clone this repo where you want and run `make` like this:  
```
git clone --depth 1 https://github.com/Kuso0taku/sibsutis-prog
cd sibsutis-prog/sem1/pract10
make 
```
or just run `make` in your console if you already have this repo.  

### Commands
- 1 - count how many every character
- 2 - inserts exclemation mark in the end of lines
- 3 - finds and counts words with dashes
- 4 - inserts 'с' (russian) after vowel and repeats vowel

### How to use
1. `./program 1 < in > out`  
**OR**
2. `./program 1`  

### Explanation
The *number* **after** *program* is a *command*.  
1. The **first** way is using **streams**. It means you can input **from** file using `<` and `>` **to** file. Content in `out` will have rewrited. Or created new one (if `out` doesn't exist).  
2. The **second** way is "regular" way to run it. Which means using program **interactively** (just by typing in console from your keyboard). **IMPORTANT**: to stop input you need to send your console **EOF** (End-of-file) signal! Regularly for *Linux* and *MacOs* it's **Ctrl+D**, but for *Windows* it's **Ctrl+Z**.  

### Uninstallation  
to remove all files have made open your console and just run:  
```
make clean
```

### See also
- back to [readme](./readme.md)  
- see [task](./task.md) in detal  
