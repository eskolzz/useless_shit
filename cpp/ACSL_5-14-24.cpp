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

string util_vectvectint2string(vector<vector<int>> table)
{
    
    
    // +---------------------------------------------------------------------+
    // | last function i have to write fuck this coding problem this was ass |
    // +---------------------------------------------------------------------+
    
    stringstream sigmasigma;
    
    for (auto& row : table) 
    {
        for (int i : row)
        {
            sigmasigma << i << " ";
        }
    }
    return(sigmasigma.str());
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


vector<vector<int>> util_dropTiles(vector<vector<int>>& table) 
{
    
    
    // +----------------------------------+
    // | this took me too long dawg :sob: |
    // +----------------------------------+


    int numRows =    table.size();
    int numCols = table[0].size();
    
    for ( int col = 0; col < numCols; col++ )
    {
        int lastRow = numRows - 1;
        
        for( int row = numRows - 1; row >= 0; row-- )
        {
            if ( table[row][col] != 0 )
            {
                if  (row != lastRow )
                {
                    
                    table[lastRow][col] = table[row][col];
                    table[row][col] = 0;
                    
                }
                lastRow--;
            }
        }
    }
    return table;
}

void util_fillTiles(vector<vector<int>>& table)
{
    
    
    // +-------+
    // | 2ezzz |
    // +-------+

    
    int numRows = table.size();
    int numCols = table[0].size();
    int power   = 8;
    
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            if(table[row][col] == 0)
            {
                table[row][col] = pow(2, power); 
                power --;
                
                if (power < 1) {power = 8;}
            }
        }
    }
}


string play2248(string boardValues, string pathValues) 
{
    
    //-------------------------------[dec]-------------------------------\\
    
    int lastTile         = 0;
    int smallestPower    = 0;
    int sumOfTiles       = 0;
    int xCoord           = 0;
    int yCoord           = 0;
    
    string returnString = "";
    
    int finalArr[8][5];
    
    vector<int> removedValues       = {};
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
        // | this cleanses all the tiles that aren't used | also keeps track of the ones that are.
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
            removedValues.push_back(((xCoord) * 10) + yCoord);
            
        }
                                          
    }
    cout << "table before we do some wierd shit to it" << endl;

    for(int i = 0; i < 8; i++)
        {

            cout << "\n";

            for(int j = 0; j < 5; j++)
            {

                cout << cleansedVec[i][j] << " ";

            }

        }
        
    util_dropTiles(cleansedVec);
    util_fillTiles(cleansedVec);
    
    cout << "\n\n\n";
        for(int i = 0; i < 8; i++)
        {

            cout << "\n";

            for(int j = 0; j < 5; j++)
            {

                cout << cleansedVec[i][j] << " ";

            }

        }
        
    return util_vectvectint2string(cleansedVec);
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
