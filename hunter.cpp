// The hunter application which can look for people
// v 0.0.2.0.1a
#include<iostream>
#include<string>
#include<fstream>
//for sleep fuction
#include<conio.h> 
//C libs to use system function
#include<cstdio>
#include<cstdlib>
//Downloading
#include<wininet.h>
#include "include/download.h"
//Internet Connectivity 
#include<winsock2.h>
#include<WinSock.h>
#include<ws2tcpip.h>
//Spidering
#include<chilkat/CkSpider.h>
#include<chilkat/CkStringArray.h>

using namespace std;

//Global Variables
string version_check;
ifstream myfile2 ("version.txt");

//Version Variable
string version = "0.0.2.0.1a";

//Prototypes
void hunt();
void update();
void clean();
void quit();

//functions
//Displays the download progress as a percentage
void showprogress(unsigned long total, unsigned long part)
    {
        int val = (int) ((double)part / total * 100);
        printf("progress: %i%%\n", val);
    }

int main()
{
	cout << " |||||	   ||||| " << endl;
	cout << " |   |	   |   | " << endl;
	cout << " |||||	   ||||| " << endl;
	cout << "       ||       " << endl;
	cout << " |	       | " << endl;
	cout << "  |	      | " << endl;
	cout << "   |||||||||| " << endl;
	cout << "Welcome to the hunter" << endl;
	cout << "Done by The Watch_dog" << endl;
    int choice;
    cout << "1.Start The Hunt" << endl;
	cout << "2.Clean" << endl;	
	cout << "3.Update" << endl;    
	cout << "4.Exit Program" << endl;
    cin >> choice;

	switch (choice)
        {
        	case 1:
        		hunt();
        		break;
        	case 2:
        		clean();
        		break;
        	case 3:
        		update();
        		break;
        	case 4:
        		quit();
        		break;
            cin.get();
        }
}


void hunt()
	{
		//	The hunter looks for people
		cout << "Enter Criteria for hunt:" << endl;
		string mystr;
        cin.ignore();
		cout << "Input Target name:";
		getline(cin, mystr);
		
		string mystr2;
		cout << "Enter age:";
		getline(cin, mystr2);

		string mystr3;
		cout << "Enter Gender:";
		getline(cin, mystr3);

		string mystr4;
		cout << "Enter race:";
		getline(cin, mystr4);

        string mystr44;
        cout << "How many hunting fields do you want me to search:" << endl;
        getline(cin, mystr44);
        int k = 0;
        int string_to_int = atoi(mystr44.c_st());
        for(k;k < string_to_int;k = k + 1)
            {
                string mystr5;
                cout << "Enter the hunting field:";
                getline(cin, mystr5);
            }   
		cout << "Check Criteria for hunt:" << endl;
		cout << "Name is:" << mystr << endl;
		cout << "Age is:" << mystr2 << endl;
		cout << "Gender is:" << mystr3 << endl;
		cout << "Race is:" << mystr4 << endl;
		cout << "Hunting Ground is:" << mystr5 << endl;

		string mystr6;
		cout << "Is This Correct? (y/n)";

		getline(cin, mystr6);

		if (mystr6 == "y")
		{
			cout << "Let The Hunt Begin!";
            CkSpider spider;
    CkStringArray seenDomains;
    CkStringArray seedUrls;
    seenDomains.put_Unique(true);
    seedUrls.put_Unique(true);

    string spider_input;
    PlayMP3( "voice/spider_website.mp3" );
    cout << "Please input the website to spider:" << endl;
    getline(cin, spider_input);
    sleep(4);
    StopMP3( "voice/spider_website.mp3" );
    seedUrls.Append(spider_input.c_str());
    
    //  Set outbound URL exclude patterns
    //  URLs matching any of these patterns will not be added to the
    //  collection of outbound links.
    spider.AddAvoidOutboundLinkPattern("*?id=*");
    spider.AddAvoidOutboundLinkPattern("*.mypages.*");
    spider.AddAvoidOutboundLinkPattern("*.personal.*");
    spider.AddAvoidOutboundLinkPattern("*.comcast.*");
    spider.AddAvoidOutboundLinkPattern("*.aol.*");
    spider.AddAvoidOutboundLinkPattern("*~*");

    //  Use a cache so we don't have to re-fetch URLs previously fetched.
    spider.put_CacheDir("Cache/spider");
    spider.put_FetchFromCache(true);
    spider.put_UpdateCache(true);

    while (seedUrls.get_Count() > 0)
        {
            const char *url = seedUrls.pop();
            spider.Initialize(url);
            //  Spider 5 URLs of this domain.
            //  but first, save the base domain in seenDomains
            const char *domain = spider.getUrlDomain(url);
            seenDomains.Append(spider.getBaseDomain(domain));
            int i;
            bool success;
            for (i = 0; i <= 4; i++)
                {
                    success = spider.CrawlNext();
                    if (success == true)
                        {
                            //  Display the URL we just crawled.
                            std::cout << spider.lastUrl() << "\r\n";
                            if (spider.get_LastFromCache() != true)
                                {
                                    spider.SleepMs(1000);
                                }
                        }
                    else
                        {
                            //  cause the loop to exit..
                            i = 999;
                        }
                }
            //  Add the outbound links to seedUrls, except
            //  for the domains we've already seen.
            for (i = 0; i <= spider.get_NumOutboundLinks() - 1; i++)
                {
                    url = spider.getOutboundLink(i);
                    const char *domain = spider.getUrlDomain(url);
                    const char *baseDomain = spider.getBaseDomain(domain);
                    if (seenDomains.Contains(baseDomain) == false)
                        {
                            //  Don't let our list of seedUrls grow too large.
                            if (seedUrls.get_Count() < 1000)
                                {
                                    seedUrls.Append(url);
                                }   
                        }
                }
        }
		}

		if (mystr6 == "n")
		{
		  loop:
			string mystr7;
			cout << "Input Target name:";
			getline(cin, mystr7);
			
			string mystr8;
			cout << "Enter age:";
			getline(cin, mystr8);
				
			string mystr9;
			cout << "Enter race:";
			getline(cin, mystr9);
			
			string mystr10;
			cout << "Enter the hunting field:";
			getline(cin, mystr10);
			
			cout << "Check Criteria for hunt:" << endl;
					
			cout << "Name is:" << mystr7 << endl;
			cout << "Age is:" << mystr8 << endl;
			cout << "Gender is:" << mystr3 << endl;
			cout << "Race is:" << mystr9 << endl;
			cout << "Hunting Ground is:" << mystr10 << endl;
				
			string mystr11;
			cout << "Is This Correct? (y/n)";
			getline(cin, mystr11);
			if (mystr11 != "y")
				{
					goto loop;
				}
			if (mystr11 == "y")
				{
					cout << "Let The Hunt Begin!" << endl;			
				}
			
		}
	}
	
void clean()
	{
		ofstream myfile("killcode.bat");
		if (myfile.is_open())
		{
			myfile << "@echo off" << endl;
			myfile << "CMDKEY" << endl;
			myfile << "" << endl;
		}
	}

void update()
{
    char url[] = "http://hackware.ddns.net/hunter/hunnter.zip";
    char url2[] = "http://hackware.ddns.net/hunter/version.txt";
    bool reload = false;
    string line;
    try
        {
            if(Download::download(url2, reload))
            if (myfile2.is_open())
                {
                    while ( getline (myfile2,line) )
                        {
                            version_check = line;
                            if(version_check > version)
                                {
                                    printf("Beginning download\n");
                                    try
                                        {   
                                            if(Download::download(url, reload, showprogress))
                                                printf("Update Complete\n");
                                        }      
                                    catch(DLExc exc)
                                        {
                                            printf("%s\n", exc.geterr());
                                            printf("Download interrupted\n");
                                        }    
                                }
                            if(version_check == version)
                                {
                                    cout << "There is no update available" << endl;
                                    main();
                                }
                            if(version_check < version)
                                {
                                    cout << "There is no update available" << endl;
                                    main();
                                }
                        }
                    myfile2.close();
                }
        }
    catch(DLExc exc)
        {
            printf("%s\n", exc.geterr());
            printf("Download interrupted\n");
            main();
        }    
    main();
}

void quit()
	{
	 cout << "Thank you for using the hunter program" << endl;
	 cin.get();
    }