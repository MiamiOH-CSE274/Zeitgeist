Author
==========
"Emrick, Garrett", emrickgj
Zeitgeist
=======

Ideas:

Implement an array that is linked when searching NthPopular. Keep index of most and least popular, and upon addition, make comparisons
to the least popular, and determine it's position from there.

As far as collisions go, I will attempt to create a "scrapArray" that will not use LinkedList implementation to increase performance 
when collisions do occur, that will simply save the index in this array of any colliding objects in that array. If a bucket has a very 
large amount of collisions, this should increase performance quite a bit (although this most likely won't be a bottleneck unless the hashing
function is bad, the array doesn't resize properly, or the data is so similar the hash function gives them similar results).

For example, let's say dog, cat, and pig all go into bucket 1 of:

[][][whale][][rabbit][snake][][]

First, add dog:

[dog][][whale][][rabbit][snake][][]

Then, since there is something already we use the new scrapArray to store that. Since horse is already there, we make it bucket 2 and store that value with the dog, so it knows
where to look in that scrapArray

[][][whale][][rabbit][snake][][]

[horse][cat][][]

Since there is still something in bucket 1, add it again to that scrapArray

[][][whale][][rabbit][snake][][]

[horse][cat][pig][]


The scrapArray only needs to be half the size of backingArray, since the main array grows at half, and should grow automatically with the backingArray for simplicity.
Also, since this one is sequential, when re-assigning the array it saves time do to having no gaps in the array, and the features of caching help.



Also have the possibility of implementing the jump method:

jump = 1 + (key %(m-1))


If{

	Load factor = number of items/ number of spaces < 1/2

	insert, remove, find should roughly equal O(1)

}

Background info
---------------
Google trends (http://www.google.com/trends/hottrends) keeps track of the most popular search terms for a given day.  In this assignment you will design a data structure that could be used by Google to implement their “trends.”

Requirements
------------
Your data structure will support four operations:

1.	`void increaseCount(string s, int amount)` – Google’s search engine will call this function each time it receives a search term, with “amount” set to 1. If your “trends” data structure has not seen the string before, add it to the data structure, and set its count to amount. If it has been seen before, increment the count for that string by amount.
2.	`int getCount(string s)` – Used by Google to determine how many times a particular search term has been seen.
3.	`string getNthPopular(int n)` – If n is 0, return the most popular search term. If n is 1, return the second most popular search term, if n is 2 return the third most popular search term … and so on.
4.	`int numEntries()` – Return the number of entries in the data structure. There should be only one entry per unique string added via increaseCount, so if increaseCount(“the”,1) is called twice, this should only be one entry.

Grading
-------
There is a trade-off here between speed of `getNthPopular`, speed of `getCounts`, and complexity of the design. It is possible to get very good speed on both methods, but it will likely involve a data structure that is a combination of two. You may want to look, for example, at the LinkedHashMap structure of Java for some inspiration.

Part of your grade for this project, if you include it in your Portfolio, will be based on the speed of your implementation.

Suggested steps
---------------
1. Download the starter code (Trends.h and Controller.cpp) from the site. Do NOT modify Trends.h (you may modify Controller.cpp if you wish).
2. Create your own Trends class (mine was called brinkmwjTrends, and it was implemented in brinkmwjTrends.h and brinkmwjTrends.cpp) which inherits from the Trends class. Note, your class declaration should look something like this: 
`class brinkmwjTrends : public Trends { 
/* member variables and methods declared here */ 
};``
3. Implement all methods of your trends class. Don’t forget the constructor and destructor, as well as the methods inherited from Trends.
4. Submit your trends class (both the .h and .cpp) and your Controller.cpp

Questions
=========

#### 1. Which type of data structure did you choose? Explain, in English, the main ideas behind your data structure.

TODO

#### 2. Explain, in English, the worst-case running time of each of your methods, along with a justification of your claims.

TODO

#### 3. Is it the case that your algorithms actually run faster, in real life, than the worst-case bounds would suggest? Why does that happen? (Hint: Usually it is because the input you receive is special, not worst-case.)

TODO


Portfolio Video
=========

Explain your code, as you would to a boss or colleague in the workplace. You will most likely want to use a screen-capture software. You should, at minimum, do the following:

1. Show your program running.
2. Show your code, briefly explaining what it is meant to do. You do NOT need to explain any of the provided code, unless you made some meaningful change you want to describe.
3. If something is not working (or if you aren't sure), explain that part carefully.
4. Explain the expected running times of your 4 main methods.

The video should certainly be less than 2 minutes long. I (or the grading assistant) ought to be able to grade your program based solely on your video, so be sure that we can see your code style, and can accurately assess what works, or doesn't work, in your program. The "Questions" above might also be things you want to talk about in your video: The video should be able to be understood even by someone that isn't in the class, and hasn't read your question answers.

#### 1. Give the link to your portfolio video on YouTube.

TODO
