import java.util.*;

class Main{
	
static final int MAX = 500001;
static int []parent = new int[MAX];
static int []Rank = new int[MAX];

public static void removeFirst(String str,String str1)
	{
        while(str.length()!=str1.length()){
		str = str.substring(0, str.length());

        }
	}
	
	public static void removeLast(String str,String str1)
	{

		 while(str.length()!=str1.length()){
		str = str.substring(str.length(),0);

        }
	}
	

static class pair
{
	char first, second;
	
	public pair(char first, char second)
	{
		this.first = first;
		this.second = second;
	}
}
static int find(int x)
{
	return parent[x] = parent[x] == x ? x :
				find(parent[x]);
}

static void merge(int r1, int r2)
{
	if (r1 != r2)
	{
		if (Rank[r1] > Rank[r2])
		{
			parent[r2] = r1;
			Rank[r1] += Rank[r2];
		}
		else
		{
			parent[r1] = r2;
			Rank[r2] += Rank[r1];
		}
	}
}

static void minimumOperations(String s1,
							String s2)
{
	
	for(int i = 1; i <= 26; i++)
	{
		parent[i] = i;
		Rank[i] = 1;
	}
	
	
	for(int i = 0; i < s1.length(); i++)
	{
		if (s1.charAt(i) != s2.charAt(i))
		{
			
			if (find(s1.charAt(i) - 96) !=
				find(s2.charAt(i) - 96))
			{
				
				
				int x = find(s1.charAt(i) - 96);
				int y = find(s2.charAt(i) - 96);
				merge(x, y);

				ans.add(new pair(s1.charAt(i),
								s2.charAt(i)));
			}
		}
	}

	System.out.print(ans.size() + "\n");
	
}

public static void main(String[] args)
{
	
	String s1, s2;
	s1 = "ab";
	s2 = "dau";
	if(s1.length()<s2.length())
    removeFirst(s2,s1);
    else
    removeFirst(s1,s2);
	minimumOperations(s1, s2);
}
}