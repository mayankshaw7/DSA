class Solution {
     List<List<Integer>>res=new ArrayList<>();
    public List<List<Integer>> combine(int n, int k) {
        List<Integer>temp=new ArrayList<>();
        backtrack(temp,n,k,1);
        return res;
    }
    private void backtrack(List<Integer>temp, int n,int k,int st){
        if(temp.size()==k){
            res.add(new ArrayList<>(temp));
            return;
        }

        for(int i=st;i<=n;i++){
            temp.add(i);
            backtrack(temp,n,k,i+1);
            temp.remove(temp.size()-1);
        }
    }
    
}