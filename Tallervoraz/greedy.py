import math, pprint, sys

## -------------------------------------------------------------------------
def ActivitySelector_GREEDY( C ):
  A = sorted( C, key = lambda c: c[ 2 ] )
  R = [ A[ 0 ] ]
  k = 0
  for m in range( 1, len( A ) ):
    if A[ m ][ 1 ] >= A[ k ][ 2 ]:
      R += [ A[ m ] ]
      k = m
    # end if
  # end for
  return( R )
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

print( len( ActivitySelector_GREEDY( data ) ) )



