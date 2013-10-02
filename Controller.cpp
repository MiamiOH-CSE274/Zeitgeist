/*****
 * Author   : brinkmwj
 * Date     : 2009-10-04
 * Sources  : All code is original
 * Purpose  : The purpose of this file is to do some VERY rudimentary timing of your increaseCount
 *            method. For the QUALITY measures I am also going to test getCount, so you might want
 *            to design some way to test out the running time of your getCount as well!
 */
#include <iostream>
#include <fstream>
#include <vector>

#include "brinkmwjTrends.h" //You will need to change this to match your own class

/*
 * processFile should:
 *  1) Create a new instance of your trends class
 *  2) Read in the file whose words you want to count: The file name is passed in as fname
 *  3) Add all words to the Trends data structure, and calculate the time per call to addtoTrends
 *  4) Use getNthPopular and getCount to print out the total results in fname + ".out"
 */
int processFile(const char* fname){
	Trends* tr = new brinkmwjTrends(); //You will need to change this to match your own class!

	//First, read in the file
	// I'm not doing much error checking here, because I am a bad person
	std::ifstream in(fname);
	std::string s;
	std::vector<std::string> wordlist;
	while(in >> s){
		wordlist.push_back(s);
	}

	//We only want to time how long addToTrends takes, so we get
	// the starting time, which is the clock time, in milliseconds
	clock_t start = clock();
	//Now add all the words to the Trends data structure
	for(unsigned int i=0; i<wordlist.size(); i++){
		tr->increaseCount(wordlist[i],1);
	}
	//Now get the end time
	clock_t end = clock();
	std::cout << "Time: " << ((1000.0*CLOCKS_PER_SEC*(end - start))/wordlist.size()) << " ms per word" << std::endl;

	//Now we will print out the complete results. This could be REALLY clow, if
	// your getNthPopular is not a little bit smart.
	std::string outfname = fname;
	outfname = outfname + ".out";
	std::ofstream out(outfname.c_str());
	for(int i=0; i< tr->numEntries(); i++){
		std::string s = tr->getNthPopular(i);
		out << tr->getCount(s) << ": " << s << std::endl;
	}
	out.close();

	delete tr;

	return end - start;
}

/*
 * The only purpose of main() is to call processFile with increasingingly larger and larger
 * files. A larger file will give a more accurate sense of how fast addToTrends is, but at some
 * point it may take so long to do the getNthPopular, that we aren't willing to wait for it to finish.
 */
int main(){

	/* These files are books from project Gutenberg. I have provided the inputs, as well as my outputs
	 * in the starter files */
	
	/* NOTE: You may want to comment some of these out!
	 * Unless your program is very speedy on all operations some of these will never finish.
	 */
	processFile("data/28885.txt");
	processFile("data/46.txt");
	processFile("data/23684.txt");
	processFile("data/1342.txt");
	processFile("data/6130.txt");
	processFile("data/4300.txt");
	processFile("data/3090.txt");

	return 0;
}
