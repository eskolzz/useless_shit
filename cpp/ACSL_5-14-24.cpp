#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the 'play2248' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING boardValues
 *  2. STRING pathValues
 */

// im gonna leave the site when i want to wtf are you gonna do about it

//if you got something that says i pasted everything here its because im on a different device and for some reason it doesn't save.







vector<vector<int>> util_vectvectint(string input, int flag) 
{
    // +-----------------------------------+------------------------------------------------+
    // |            Information            |                   Reasoning                    |
    // +-----------------------------------+------------------------------------------------+
    // | Fuck this function respectfully.  | didn't work for half the time i was doing this |
    // +-----------------------------------+------------------------------------------------+

    stringstream            ss(input);
    string                  idkthingy;
    vector<vector<int>>     things;
    vector<int>             tempVec;
    
    int x;
    while (ss >> x)
    
    {
        
        tempVec.push_back(x);
        if(tempVec.size() == 5)
        
        {
            
            things.push_back(tempVec);
            tempVec.clear();
            
        }
        
    }
    
    return things;
    
}





vector<int> util_vectint(string& input, int flag) 
{
    // +---------------------------------+
    // | what do mexican programmers use |
    // +---------------------------------+
    // | si ++                           |
    // +---------------------------------+

    stringstream    ss(input);
    string          idkthingy;
    vector<int>     things;
    
    if(flag == 0)
    {
        
        while ( getline(ss, idkthingy, ' ' )) 
        {
            
            things.push_back(stoi(idkthingy));
            
        } 
        
    }      
    
    return things;
    
}




int util_miscInt(int sum) //pasted from unknown cheats...
{
    // +------------------------------------------------------+
    // |                      multi tool                      |
    // +------------------------------------------------------+

    int result  = 1;
    
    while (result < sum)
    {
        result  *= 2;
    }
    
    return result;

}


vector<vector<int>> util_dropTiles(vector<vector<int>> table)
{
    
    vector<vector<int>> cleansedVector = table;
    bool flag                          = true;
    
    while(true)
    {
        
        for(int i = 0; i < 7; i++) //first checky if the table is already sorted, then move on
        {
            for(int j = 0; j < 5; j++)
            {
                if(cleansedVector[j][i-1] != 0)
                {
                    
                    cout << "continued thru index (" + to_string(j) + "," + to_string(i) + ")    |    skipped value: " + to_string(cleansedVector[j][i-1]) + " | value under was: " + to_string(cleansedVector[j][i]) << endl;
                    
                    continue;
                }
                
                else 
                {
                    flag = false;
                }
            }
        }
        
        if (flag)
        {
            break;
        }
        else 
        {
            for(int i = 0; i < 7; i++) //first checky if the table is already sorted, then move on
            {
                for(int j = 0; j < 5; j++)
                {
                    if(cleansedVector[j][i-1] != 0)
                    {
                       cleansedVector[j][i-1] = cleansedVector[j][i];
                    }
                }
            } 
        }
    }
    return(cleansedVector);
}


string play2248(string boardValues, string pathValues) 
{
    
    //-------------------------------[dec]-------------------------------\\
    
    int lastTile       = 0;
    int smallestPower  = 0;
    int sumOfTiles     = 0;
    int xCoord         = 0;
    int yCoord         = 0;
    
    int finalArr[8][5];
    
    vector<int> pValVec             = util_vectint(pathValues, 0);
    vector<vector<int>> pBoardVec   = util_vectvectint(boardValues, 0);
    vector<vector<int>> cleansedVec = util_vectvectint(boardValues, 0);
    
    
    
    //-------------------------------[functions]-------------------------------\\
    
    //<h1> summerupper
    for (int i = 0; i < pValVec.size(); i++)
    {   
        xCoord                                       = (pValVec.at(i)) / 10;
        yCoord                                       = (pValVec.at(i)) % 10;
        sumOfTiles                                   = sumOfTiles += pBoardVec[xCoord - 1][yCoord - 1];
    }
    
    //<h1\>
    
    //-------------------------------[cleanser]-------------------------------\\
    
    
    cleansedVec[(pValVec.back() / 10) - 1][(pValVec.back() % 10) - 1] = util_miscInt(sumOfTiles); //step uno;
    
    
    for (int i = 0; i < pValVec.size(); i++)
    {   

        // +----------------------------------------------+
        // | this cleanses all the tiles that aren't used |
        // +----------------------------------------------+
        

        int cTile                                    = pBoardVec[xCoord - 1][yCoord - 1];
        xCoord                                       = (pValVec.at(i)) / 10;
        yCoord                                       = (pValVec.at(i)) % 10;
        
        
        
        if (xCoord == (pValVec.back() / 10) && yCoord == (pValVec.back() % 10))
        {
            cout << "SKIPPED VALUE: " + to_string(cTile) + " at index: (" + to_string(xCoord) + "," + to_string(yCoord) + ")" << endl;
        }
        
        else {
            
            cleansedVec[xCoord - 1][yCoord - 1] = 0;
            cout << "removed value: " + to_string(cleansedVec[xCoord - 1][yCoord - 1]) + " at index: (" + to_string(xCoord) + "," + to_string(yCoord) + ")" << endl;
            cout << "conconcted xy coordinates were: (" + to_string((xCoord * 10) + (yCoord)) + ")" << endl;
        }
                                          
    }
    
    for (int i = 0; i < pValVec.size(); i++)
    {   
        
        xCoord                                       = (pValVec.at(i)) / 10;
        yCoord                                       = (pValVec.at(i)) % 10;
        
    }
    
    
    
    
    //-------------------------------[debuggah]------------------------------\\
    
        cout << "----------[ header ]----------"      << endl;
        cout << "first step  |  "                        << util_miscInt(sumOfTiles) << endl;
        
        for(int i = 0; i < 8; i++)
        {

            cout << "\n";

            for(int j = 0; j < 5; j++)
            {

                cout << cleansedVec[i][j] << " ";

            }

        }

        cout << "\n\n";
    
        cout << "----------[ enderr ]----------"      << endl << endl;

    return("sum of tiles == " + to_string(sumOfTiles) + "  |   smallestPower == " + to_string(smallestPower));
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string boardValues;
    getline(cin, boardValues);

    string pathValues;
    getline(cin, pathValues);

    string result = play2248(boardValues, pathValues);

    fout << result << "\n";

    fout.close();

    return 0;
    
                                      /*.::---:=-=:-::                                        
                             -::...............:.............                                
                          ::......................-::-:........::                            
                      -............ ..-:-=+-+**##%*#*=-::.:.:.....:                          
                  -:..........:....:.-*+##*#%%@@@@%%%%+**+-*++.::....                        
                 ......   ....:::.-+-=%=####%@@@@@@@@@@@%#%@@@%*-:....                       
               -:.. .....:.++:--:-+++**+##%%@@%@@@@@@@@@@@@@@@@@@##=:.                       
              :.... ...::.--+--*====++++%%@%@@@@%@@@@@@@@@@@%@@@@@@#++-: ==                  
            :.........:=-=*-*###@#%%%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@##**=-::.                
           ..... ...:--++#+%#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*%==:-:..              
         :... .....::++*=+#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%+*::.....            
        :.. .    :==+%+%#%@@%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%@*---..:...          
       ...... ...-=*+#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*--:-......:         
      :....... ..:=%%@@%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%+:=*-:...::.-       
     -....   ....-#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#=*+#--...:-::      
    -...........-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%*%@+...:-::.:     
    :........:.-*%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%+%%++:.:.:::.:    
   *..........-%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%#+#-....:..-    
   :.........:+@@@@@@@@@@@@@%##*%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%@@@@@@@@%@#==+:.::....:   
   :.........-*@@@@@@#*+-:-.:-=-==+*+%%@@@@@@@@@@@@@@@@@@%#%*=:-.---::++#*#@@+#%*.:.::....   
  :=.........-*@@#=::-.........:-::...:=#%#@@@%%@@@@@@*::.::.:-.......:-:.::+#*%#:-:::....   
  ::.:.......-%%=.:::::..........:.......::=**#%#*%#+-:......................=@%*-=:..:..    
    ...:.....+%:.....::::....+*#+::.......:.*+#%=%=+:.....:...:-:...--.:-:...=@@+-=-=:...=   
    .........=*:.::-+%##@@%%@@@@@@@#==....:-+#%#+==:......:-@@@@%@%@@%@@#**-=-#%*:-.......   
   +..:.....:+#*#++*#%#=:..........:+#%%++=+#@@@@#=---+*%*=::...:-++#%%@@@@@@#%%+:::.....-   
   :.........-#%@@*:.......  ...#@-.:==%@@@@@@@@@@@@@@@%=:=%-. .-+..::..=#@@@@@@+:.....:.-=  
   ...........+@@%:..:==*-.....+@@#:.=:*%@@@@@@@@@@@@@@%#*#@% .....+@#*-=*%@@@@@#:-.....:+   
   .... .....:#@@@%@%@%%@%#*##%@@@@@@%%+%@@@@@@@@@@@@@@@@@@@@@#+=*@@@%@@@@@@@@@%#=......:    
   :..    ...+@@@@@@@@@@@@@@%@@@@@@@@@@%@@@@@@@@@@@@@@@@@@@@@@%%@@@@@@@@@@@@@@@%=...::::.    
   -..    ...*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=.....:      
   :....  ..:+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*.:.:=+      
   ::...  ..:*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%-...-#=      
  :: ...  ..:*%@@@@@@@@@@@@@@@@@@@@@@@%%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#:...*@%*     
  ::  :.....:+#@@@@@@@@@@@@@@@@@@@@@@%+@@%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%+..:#@@=     
  ==   -:...:#@%@@@@@@@@@@@@@@@@@@@@@==#@*#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+..%@@@%     
  ::  #-....:*%%@@@@@@@@@@@@@@@@@@@@@+=+*:.*@@@@@@@#*@@@@@@@@@@@@@@@@@@@@@@@@@@@*.+@@@@@     
  .: *+-:...-=*%@@@@@@@@@@@@@@@@@@@@@#:-=:..+@@@%*..*%@%@@@@@@@@@@@@@@@@@@@@@@@%-.%*%@@%     
   +- +*+:..-+*%%@@@@@@@@@@@@@@@@@@@@@@%*+=:-=*+++#%%@@@@@@@@@@@@@@@@@@@@@@@@@@=.=@@@@@      
    -=*%%%=-=-*%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%*#@@@@%%      
      *#**::..+*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-:=%@@@@       
      ::::..-:+*%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@==-%=#%        
       :::.....=*#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%-::=%#         
         ......:=*#%@@@@@@@@##*#%%%%@@@@@@@@@@@@@@@@@@@@@@@@@@%###@@@@@@@@@@@@=:.:           
              .:-=*%%@@@@@@%++=.......:..:.--=+++=+=====+==-*+%@@@@@@@@@@@@@@@@              
               ..:=#%%@@@@@@@@@%*-.:..:..:-=**==-=*+#+=++%%@@@@@@@@@@@@@@@@@@@               
                .:-+#=%%@@@@@@@@@@@#-++-:-+:+*##+-#%@%@@@@@@@@@@@@@@@@@@@@@@@                
                 :.:=+*%%@@@@@@@@@@@@@%*=:+-*=+**%*###@@@@@@@@@@@@@@@@@@@@@@                 
                   ..-++#%%@@@@@@@@@@@@@@@@@%@%%%@%@@@@@@@@@@@@@@@@@@@@@@@%%                 
                    :..--+#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%@                    
                      ...-:%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%#                      
                       .:..-+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#*+                        
                         =..:+#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@--+                         
                           :..:=#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%+-+                           
                             :...::+#%%@%%%%@%@@@@@@@@@@@@@%%*=%                             
                               ..:....=:---..:..::==*+#+==+*=+*                              
                                    ::.................-+*/                                                           

}
