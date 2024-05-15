
int util_idkwhat2namethis(string input, vector<int> vect) //useless fucking function idk why i made this (there was more than this before)
{
    int xCoord   = stoi(input) / 10;
    int yCoord   = stoi(input) % 10;
    
    int tempSum  = 0;
    int temp1    = 0;
    int temp2    = 0;
    
    int tempArr[8][5];
    
    cout << temp2 << endl;
    
    cout << "temp1 == " << temp1;
    cout << "\n" << endl;
    cout << "temp2 == " << temp2;
    cout << "\n" << endl;
    cout << "x == " << xCoord;
    cout << "\n" << endl;
    cout << "y == " << yCoord;
    cout << "\n" << endl;
    
    return
    (
        tempArr[xCoord][yCoord]
    );
    
}
