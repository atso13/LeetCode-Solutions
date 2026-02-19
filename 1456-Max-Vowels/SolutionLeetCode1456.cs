public class Solution 
{
    public int MaxVowels(string s, int k) 
    {
        int counter = 0;
        int maxVowel = 0;

        for(int i = 0; i < k; i++) 
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                counter++;
        }
        
        maxVowel = counter;

        for(int i = k; i < s.Length; i++) 
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                counter++;

            if(s[i - k] == 'a' || s[i - k] == 'e' || s[i - k] == 'i' || s[i - k] == 'o' || s[i - k] == 'u')
                counter--;

            if(counter > maxVowel)
                maxVowel = counter;
        }

        return maxVowel;
    }
}
