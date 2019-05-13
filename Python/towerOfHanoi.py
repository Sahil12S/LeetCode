# Implement Tower of hanoi
# Given 3 pegs, transfer N rings fromm one peg to another.

numOfPegs = 3

def ComputeTowerOfHanoi( num_rings ):
    # Create pegs
    pegs = []
    for i in range( numOfPegs ):
        pegs.append( [] )
    
    # Put rings in first peg
    for ring in range( num_rings ):
        pegs[0].append( num_rings - ring )

    result = []
    TowerOfHanoiHelp( num_rings, pegs, 0, 1, 2, result )
    return result

# Helper function
def TowerOfHanoiHelp( num_rings_to_move, pegs, from_peg, to_peg, use_peg, result ):
    if num_rings_to_move > 0:
        TowerOfHanoiHelp( num_rings_to_move - 1, pegs, from_peg, use_peg, to_peg, result )
    
        pegs[to_peg].append( pegs[from_peg][-1] )
        pegs[from_peg].pop()
        print( "Moving from peg {0} to peg {1}".format( from_peg, to_peg ) )
        print( "Pegs: ", pegs )

        result.append( [from_peg, to_peg] )
        TowerOfHanoiHelp( num_rings_to_move - 1, pegs, use_peg, to_peg, from_peg, result )


if __name__ == "__main__":
    result = ComputeTowerOfHanoi( 3 )
    print( result )
