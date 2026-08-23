import java.util.*;
class BalancedParanthesis {
    public static boolean isBalanced(String s) {
        Stack<Character> st = new Stack<>();
        for(int i=0; i<s.length(); i++) {
            char c = s.charAt(i);

            if(c=='{' || c=='(' || c=='[') {
                st.push(c);
            } else {
                if(st.isEmpty()) return false;
                if((c=='}' && st.peek()!='{') || (c==']' && st.peek()!='[') || (c==')' && st.peek()!='(')) return false;
                st.pop();
            }

        }
        return st.isEmpty();
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        if(isBalanced(s)) System.out.println("String is Balanced");
        else {
            System.out.println("String is Not Balanced");
        }
        sc.close();
    }
}
