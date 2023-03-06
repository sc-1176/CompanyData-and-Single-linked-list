# CompanyData-and-Single-linked-list
Contains a class to build a singly linked list and a class to build a spreadsheet based on employee data

I haven't slept in 2 days, this will not be a thorough read me.
In fact I'm fairly sure I misinterpreted the concept behind the employee class as I am just now realizing using a class hierarchy with inheritance might have made this a bit easier.
However it's efficient and is a lot easier to read and understand than an inherited class is, so I went with that. 
Company data has no way of deleting an employee as of right now.
You can add employees however, only their name and the hours they work a week are required -- the program does the rest.


This is just a single linked list class and a class that builds a spreadsheet of company data using a list data structure.
If you'd like to test the code for yourself I have an int main() attached to the project with prebuilt values for you to mess with at your leisure to test what I have built. 
The classes themselves are fairly simple because I'm still shaky on pointers and I've commented clarifications for anything that might be vague.

For the singly-linked-list class I've included below the sample screenshots of the output. 

Addition to the start and end of the list and the empty function, both being used in tandem

![image](https://user-images.githubusercontent.com/124931156/223281266-fe11f7f3-7907-402f-bce0-d280fc9a4473.png)


Front, back, and deletion at different points functions in tandem

![image](https://user-images.githubusercontent.com/124931156/223281559-efed0de7-b390-4d9a-856f-27156ca8d51a.png)


Insert at an index and the results of an attempted addition to an index out of bounds

![image](https://user-images.githubusercontent.com/124931156/223281712-dc91c0b2-76b9-4ead-9178-b539c5a924f7.png)


Removal at a specific index and the results of an attempted removal at an index out of bounds

![image](https://user-images.githubusercontent.com/124931156/223281920-2241454c-a7e7-4e17-9662-bdc149db2279.png)


Find value and return an index function and the results of searching for a value not in the list

![image](https://user-images.githubusercontent.com/124931156/223282013-72a9e114-1940-49e0-947d-05bc4aadedca.png)


The entirety of the employee data class output given only the names and hours worked of the employees. None of these names are real people.

![image](https://user-images.githubusercontent.com/124931156/223282175-c974b52a-3d9c-48c7-873f-3e42a1380ecc.png)

I'm more than willing to rewrite the employee class at a late date should a more efficient method be found.
Or if I really did misinterpret the requirements. Thank you for reading, have a good day.
