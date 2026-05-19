using System;

public class Solution
{
    public static int MinimizedMaximum(int n, int[] quantities)
    {
        int maxQuantity = 0;
        for (int i = 0; i < quantities.Length; i++)
        {
            maxQuantity = Math.Max(maxQuantity, quantities[i]);
        }

        int low = 1;
        int high = maxQuantity;
        int mid;

        while (low < high)
        {
            
            mid = low + (high - low) / 2;


            if (CanSplit(n, quantities, mid))
            {
                high = mid; 
            }
            else
            {
                low = mid + 1; 
            }
        }

        return low;
    }

    private static bool CanSplit(int n, int[] quantities, int x)
    {
        int storeCount = 0;
        
        for (int i = 0; i < quantities.Length; i++)
        {

            storeCount += (quantities[i] + x - 1) / x;
        }
        
        return storeCount <= n;
    }
}