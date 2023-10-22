# Stacks, Queues - LIFO, FIFO

<h2>Description</h2>
This project is about creating an interpreter for the Monty byte files which relies on the stack data structure.

<h2>Compilation</h2>
to compile the interpreter you need to use the following command:

```
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```
<h2>Usage</h2>
To run the interpreter you need to use the following command:

```
./monty file_name
```
where file is the path to the file containing Monty byte code.

<h2> Monty byte code </h2>
Monty byte code is a language that is compiled into Monty byte files. It relies on a unique stack data structure with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty byte codes.


<h2>Supported Operation</h2>
<table>
  <thead>
    <th>opcode</th>
    <th>Description</th>  
  </thead>
  <tbody>
    <tr>
      <td>push</td>
      <td>pushes an element to the stack.</td> 
    </tr>
    <tr>
      <td>pall</td>
      <td>prints all the values on the stack, starting from the top of the stack.</td> 
    </tr>
    <tr>
      <td>pint</td>
      <td>prints the value at the top of the stack.</td> 
    </tr>
    <tr>
      <td>pop</td>
      <td> removes the top element of the stack.</td> 
    </tr>
    <tr>
      <td>nop</td>
      <td>doesn’t do anything.</td> 
    </tr>
    <tr>
      <td>swap</td>
      <td>swaps the top two elements of the stack.</td> 
    </tr>
    <tr>
      <td>pchar</td>
      <td>prints the char at the top of the stack.</td> 
    </tr>
    <tr>
      <td>pstr</td>
      <td>prints the string starting at the top of the stack.</td> 
    </tr>
    <tr>
      <td>rotl</td>
      <td>
        rotates the stack to the top.<br>
        The top element of the stack becomes the last one, and the second top element of the stack becomes the first one.
      </td> 
    </tr>
    <tr>
      <td>rotr</td>
      <td>
        rotates the stack to the bottom.<br>
        The last element of the stack becomes the top element of the stack.
      </td> 
    </tr>
    <tr>
      <td>add</td>
      <td>adds the top two elements of the stack.</td> 
    </tr>
    <tr>
      <td>sub</td>
      <td>subtracts the top element of the stack from the second top element of the stack.</td> 
    </tr>
    <tr>
      <td>div</td>
      <td>divides the second top element of the stack by the top element of the stack.</td> 
    </tr>
    <tr>
      <td>mul</td>
      <td> multiplies the second top element of the stack with the top element of the stack.</td> 
    </tr>
    <tr>
      <td>mod</td>
      <td>computes the rest of the division of the second top element of the stack by the top element of the stack.</td> 
    </tr>
    
    
  </tbody>
</table>
<h2>Authors</h2>
<a href="https://github.com/AmiraWalid1">Amira Walid</a>
<br>
<a href="https://github.com/11121997">Nawal Khaled</a>
