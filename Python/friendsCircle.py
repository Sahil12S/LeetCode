"""
There are N students in a class. Some of them are friends, while some are not. 
Their friendship is transitive in nature. For example, if A is a direct friend of B,
and B is a direct friend of C, then A is an indirect friend of C. 
And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class.
If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not.
And you have to output the total number of friend circles among all the students.
"""

# Using Python's MyPy library for function annotations

from typing import List


def helper( M: List[List[int]], visited: List[bool], i: int ) -> None:
    for j in range( len( M ) ):
        if M[i][j] and not visited[j]:
            visited[j] = True
            helper( M, visited, j )


def friendCircle( M: List[List[int]] ) -> int:
    visited = [False] * len( M )

    count = 0

    for i in range( len( visited ) ):
        if not visited[i]:
            helper( M, visited, i )
            count += 1
    
    return count


def main():
    M = [ [1,1,0], [1,1,0], [0,0,1] ]

    print( "Ans: ", friendCircle( M ) )


if __name__ == "__main__":
    main()
    
