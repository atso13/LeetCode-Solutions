using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Linked1_targol
{
    internal class Program
    {
        static void Main(string[] args)
        {

        }

        //LeetCode 19 
        public static Node<int> RemoveNthFromEnd(Node<int> lst, int n)
        {
            if (lst == null) 
                return null;
            if (n == 0)
                return lst;
            Node<int> temp = lst;
            Node<int> renode = lst;
           
            for(int i = 0; i<n; i++)
            {
                temp = temp.GetNext();    
            }
            if (temp == null)
                return lst.GetNext();

            while (temp.HasNext())
            {
                temp =temp.GetNext();
                renode = renode.GetNext();

            }
            renode.SetNext(renode.GetNext().GetNext());
           
            return lst;
        }
    }


//the class we use in this Soultion : 

    public class Node<T>
    {
        private T value;
        private Node<T> next;
        //-----------------------------------
        //constructors
        public Node(T value)
        {
            this.value = value;
            this.next = null;
        }
        public Node(T value, Node<T> next)
        {
            this.value = value;
            this.next = next;
        }
        //-----------------------------------
        //getters
        public T GetValue()
        {
            return this.value;
        }
        public Node<T> GetNext()
        {
            return this.next;
        }
        //-----------------------------------
        //setters
        public void SetValue(T value)
        {
            this.value = value;
        }
        public void SetNext(Node<T> next)
        {
            this.next = next;
        }
        public bool HasNext()
        {
            return (this.next != null);
        }
        //-----------------------------------
        //ToString
        public override string ToString()
        {
            return value + " --> " + next;
        }
    }
}