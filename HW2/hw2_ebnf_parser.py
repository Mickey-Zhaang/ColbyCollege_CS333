# hw2_ebnf_parser.py
# Stephanie R Taylor Fall 2025
# Parse a very simple expression grammar expressed in EBNF
# The grammar involves a single expression with integers, addition, and subtraction
# The test code uses the string "3-23+4" and creates a tree
#
#                     ExpressionNode
#                 left      op=+     right
#                   /                        \
#                  /                          \
#    ExpressionNode                IntegerNode
#   left      op=-    right               value=4
#     |                       |
#     |                       |
#  IntegerNode       IntegerNode
#   value=3              value=23
#
# which is printed out top-to-bottom using indentation to indicate the level of the tree. It puts the operator first, then the left kid, then the right kid. So, the output of the test code is
# +
#   -
#     3
#     23
#   4

# Concrete syntax
#
# Expression -> Integer { AddOp Integer }
# AddOp -> + | -

# Node types for Abstract Syntax Tree
#
# Expression = Expression left, string op, Expression right
# Integer = int value
import hw2_tokenizer as tokenizer

class ExpressionNode:
    def __init__( self, left, op, right ):
        self.left = left
        self.op = op
        self.right = right

    def print( self, whitespace = "" ):
        print( whitespace + self.op )
        self.left.print( whitespace + "  " )
        self.right.print(  whitespace + "  " )

class IntegerNode:
    def __init__( self, value ):
        self.value = value
        
    def print( self, whitespace = "" ):
        print( f"{whitespace}{self.value}" )

# Whenever we enter a parseX function, we have already retrieved the first token in that statement.
class Parser:
    def __init__( self, filename ):
        self.tokenizer = tokenizer.Tokenizer( filename )
        self.ast = None # this will be the root of the abstract syntax tree
        self.token = None # this is the most recently read token
        
    def getToken(self):
        self.token = self.tokenizer.getToken()
        print( "Getting Token: ", self.token )
        
    def parseInteger( self ):
        # make sure the current token is an integer. if it is, make an AST node for it
        # and move on to the next node.
        # If it isn't print an error message and return None.
        if self.token.isInteger():
            e = IntegerNode( int(self.token.value) )
        else:
            print( "expecting an integer, but found:", self.token )
            return
        self.getToken() # move to first after this expression
        return e
        
    def parseExpression( self ):
        c = self.parseInteger()
        while self.token is not None and self.token.value in "+-":
            op = self.token.value
            self.getToken() # move into first token of next expression
            # and return a Tree that puts any other +/- operations we have already
            # seen in the left kid, so they are evaluated first.
            c = ExpressionNode( c, op, self.parseInteger() )
        return c       
            
    def buildTree( self ):
        self.getToken()
        self.ast = self.parseExpression()

if __name__ == "__main__":
    p = Parser("1 - 2 + 3 - 4")
    p.buildTree()
    p.ast.print( "" )
