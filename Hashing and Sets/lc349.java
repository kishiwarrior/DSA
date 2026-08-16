class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> st = new HashSet<>();
        for(int i = 0; i < nums1.length; i++)
        {
            if(!st.contains(nums1[i]))
                st.add(nums1[i]);
        }
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < nums2.length; i++) {
            if(st.contains(nums2[i])){
                list.add(nums2[i]);
                st.remove(nums2[i]);
            }
            
        }
        int[] res = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            res[i] = list.get(i);
        }
        return res;
    }
}