import math, pprint, sys

## -------------------------------------------------------------------------
def ActivitySelector_DP_Aux( A, i, j, M ):
  if M[ i ][ j ] == -math.inf:
    S = []
    for k in range( i, j + 1 ):
      if A[ k ][ 1 ] >= A[ i ][ 2 ] and A[ k ][ 2 ] <= A[ j ][ 1 ]:
        S.append( k )
      # end if
    # end for

    if len( S ) == 0:
      M[ i ][ j ] = 0
    else:
      q = -math.inf
      for k in S:
        v = 1 + ActivitySelector_DP_Aux( A, i, k, M )
        v = v + ActivitySelector_DP_Aux( A, k, j, M )
        if q < v:
          q = v
        # end if
      # end for
      M[ i ][ j ] = q
    # end if
  # end if
  return M[ i ][ j ]
# end def

## -------------------------------------------------------------------------
def ActivitySelector_DP( A ):
  C = sorted( A, key = lambda a: a[ 2 ] )
  C.insert( 0, [ "__not_valid__", -math.inf, 0 ] )
  C.append( [ "__not_valid__", C[ -1 ][ 2 ], math.inf ] )
  M = [ [ -math.inf for j in range( len( C ) ) ] for i in range( len( C ) ) ]
  return ActivitySelector_DP_Aux( C, 0, len( C ) - 1, M )
# end def


## Read data
if len( sys.argv ) < 2:
  print( "Usage: python3", sys.argv[ 0 ], "input_file" )
  sys.exit( 1 )
# end if

data = []
with open( sys.argv[ 1 ] ) as f:
  for line in f:
    for t in line.split( '\n' ):
      d = t.split( ' ' )
      if len( d ) >= 3:
        data.append( [ d[ 0 ], int( d[ 1 ] ), int( d[ 2 ] ) ] )
      # end if
      # end for
    # end for
  # end for
# end with


print( ActivitySelector_DP( data ) )

## eof - test.py
