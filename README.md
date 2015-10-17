Sublime-ManiaScript
===============

ManiaScript syntax highlighting and autocompletion for Sublime Text 2 and 3.

##### This is a fork of the repo [ST2-ManiaScript](https://github.com/Tgys/ST2-ManiaScript)


Installation
------------

### Primary method
In Sublime Text 2, open the menu `Preferences -> Browse Packages...` then create the folder ManiaScript and copy-paste the files `ManiaScript.tmLanguage` and `ManiaScript.sublime-completions` in there.

### Alternative method
- Install [Package Control](http://wbond.net/sublime_packages/package_control)
- Install the package `ManiaScript`
- Restart SublimeText 2 or 3
- Enjoy!


Content
-------

### Updated Syntax Coloring & Autocompletion

`ManiaScript.tmLanguage`
`ManiaScript.sublime-completions`

These files define a language grammar for syntax highlighting ManiaScript files. You'll get the following:
- SublimeText will automatically load this syntax when you'll open a .Script.txt file
- Highlight most of the ManiaScript classes/enums/variables
- You can autocomplete some ManiaScript functions and classes

### Snippets
<table>
	<tr>
		<th>Snippet</th>
		<th>Trigger</th>
		<th>Output</th>
	</tr>
	<tr>
		<td>#Include frame</td>
		<td>Include</td>
		<td>`#Include "..." as ...`</td>
	</tr>
	<tr>
		<td>declare</td>
		<td>dec</td>
		<td>`declare ... ...;`</td>
	</tr>
	<tr>
		<td>declare persistent</td>
		<td>dec:p</td>
		<td>`declare persistent ... ... for ...;`</td>
	</tr>
	<tr>
		<td>function</td>
		<td>fun</td>
		<td>```... ... (...) {
			...
		}```</td>
	</tr>
	<tr>
		<td>cast</td>
		<td>via strg+shift+p</td>
		<td>`(<Selection> as ...)`</td>
	</tr>
</table>


Contribution
------------

Thanks first to [Tgys](https://github.com/Tgys) for the first version of this syntax.

Please feel free to comment, suggest, stab, pull request and fork.
