Zeitgeist
=======

Background info
---------------
Google trends (http://www.google.com/trends/hottrends) keeps track of the most popular search terms for a given day.  In this assignment you will design a data structure that could be used by Google to implement their “trends.”

Stages
------

1. Develop use cases (written description, homework)
2. Implement naive version of data structure (done for you)
3. Implement code to test run times of use cases (homework)
4. Implement real version(s) of data structure (homework)
5. Evaluate your data structure version(s) using use cases (in class)

Data Structure Requirements
------------
Your data structure will support four operations:

1.	`void increaseCount(string s, unsigned int amount)` – Google’s search engine will call this function each time it receives a search term, with “amount” set to 1. If your “trends” data structure has not seen the string before, add it to the data structure, and set its count to amount. If it has been seen before, increment the count for that string by amount.
2.	`unsigned int getCount(string s)` – Used by Google to determine how many times a particular search term has been seen.
3.	`string getNthPopular(unsigned int n)` – If n is 0, return the most popular search term. If n is 1, return the second most popular search term, if n is 2 return the third most popular search term … and so on.
4.	`unsigned int numEntries()` – Return the number of entries in the data structure. There should be only one entry per unique string added via increaseCount, so if increaseCount(“the”,1) is called twice, this should only be one entry.

Stage 1: Due Tuesday 11/25, by start of class
--------------------------------------
1. Download the starter code
2. Create some additional use cases that measure running times of things: In particular, create a use case that shows that smarterTrends is still a very bad data structure.
2. Create your own Trends class (mine was called brinkmwjTrends, and it was implemented in brinkmwjTrends.h and brinkmwjTrends.cpp) which inherits from the Trends class. Note, your class declaration should look something like this: 
`class brinkmwjTrends : public Trends { 
/* member variables and methods declared here */ 
};``
See the naiveTrends and smarterTrends .h and .cpp for examples
3. Implement all methods of your trends class. Don’t forget the constructor and destructor (if needed), as well as the methods inherited from Trends.

Stage 2: Due Thursday 12/4, by 11:59pm
-------------------------------------
1. Using github, find the Trends classes of at least two other teams
2. Download their classes and test them using your use cases
3. If possible, develop new use cases for which your data structure beats theirs
4. If possible, develop new use cases for which their data structure beats yours

Demo Video
=========

Explain your code, as you would to a boss or colleague in the workplace. You will most likely want to use a screen-capture software. You should, at minimum, do the following:

1. Show your program running.
2. Show your code, briefly explaining what it is meant to do. You do NOT need to explain any of the provided code, unless you made some meaningful change you want to describe.
3. If something is not working (or if you aren't sure), explain that part carefully.
4. Explain the expected running times of your 4 main methods.
5. Explain the use cases that you used to test your code, and tell who else you tested your use cases on. Tell whether your code is faster or slower than the other teams you compared to, and explain why, using the evidence from your testing.

The video should certainly be less than 2 minutes long. I (or the grading assistant) ought to be able to grade your program based solely on your video, so be sure that we can see your code style, and can accurately assess what works, or doesn't work, in your program. 

#### 1. Give the link to your portfolio video on YouTube.

TODO
