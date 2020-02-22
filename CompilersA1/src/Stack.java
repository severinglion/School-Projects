import java.util.ArrayList;

/**
 * Stack data structure to hold Tokens. 
 */
class Stack {
    private ArrayList<Token> stack;

    Stack(){
        stack = new ArrayList<Token>();
    }

    //add a token into the stack
    public void push(Token token){
        if(token != null){
            stack.add(token);
        }
    }

    //remove the last item inserted
    public Token pop () {
        if(!stack.isEmpty()){
            Token tok = stack.remove(stack.size() - 1);
            return tok;
        }
        return null;
    }

    //checks if the stack is empty
    public Boolean isEmpty(){
        return stack.isEmpty();
    }

    public Boolean isStackRelavant(){
        //System.out.println("Debugging the stack relavant");
        for(int i = 0; i < stack.size(); i++){
            Token tok = stack.get(i);
            //System.out.println(i + ": " + tok + " " + tok.relavant);
            if(!tok.relavant)
                return false;
        }
        return true;
    }

}