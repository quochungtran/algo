class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words;
        vector<string> res;
        int max = 1;
        
        // find the number of word in string s
        int i = 0 ;
        while( i < s.size())
        {
            string word ;
            while (s[i] != ' ' && i < s.size() )
            {
                word.push_back(s[i]);
                i++;
            }
            words.push_back(word);
            
            if (word.size() >= max)
                max = word.size();
            
            i++;
            
        }
        
        // max is the number of required word
        for (int j = 0; j < max ; j++ )
        {
            string wordVertical;
            
            for (int k = 0 ; k < words.size() ; k++)
            {
                if (j+1 > words[k].size())
                {
                    wordVertical.push_back(' ');
                }
                else
                    wordVertical.push_back(words[k][j]);
            }
            
            int z = wordVertical.size();
            
            // handle the word by delete spaces in the bottom of word 
            while(wordVertical[z-1] == ' ')
            {
                wordVertical.pop_back();
                z--;
            }
            
            res.push_back(wordVertical) ;
        }
        return res;
    }
};