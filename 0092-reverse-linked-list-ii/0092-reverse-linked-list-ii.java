/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        // Base case: agar list khali hai ya single node hai, toh reverse karne ki zaroorat nahi
        if (head == null || head.next == null) {
            return head;
        }
        
        // Dummy node banaya taaki agar 'left == 1' (head se hi reverse karna ho), toh edge case handle ho jaye
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        
        // 'prev' pointer ko 'left' se theek ek node pehle tak lekar jayenge
        ListNode prev = dummy;
        for (int i = 1; i < left; i++) {
            prev = prev.next;
        }

        // 'curr' pointer humesha us node par rahega jo starting me 'left' position par tha
        ListNode curr = prev.next;
        int cycle = right - left;
        
        // Loop chala kar links ko modify karenge (In-place shift)
        for (int i = 0; i < cycle; i++) {
            ListNode temp = prev.next;
            prev.next = curr.next;
            curr.next = curr.next.next;
            prev.next.next = temp;
        }
        
        // Dummy ka agla node hi humari modified list ka actual head hoga
        return dummy.next;
    }
}
/*
🔄 Cycle 1 (Jab i = 0)Shuruat me list aisi dikh rahi hai: 1 (prev) -> 2 (curr) -> 3 -> 4 -> 5ListNode temp = prev.next;temp ban gaya node 2. (Humne node 2 ka rasta yaad rakhne ke liye use save kar liya).prev.next = curr.next;prev (1) ka next ab direct curr.next (3) ko point karega.List ban gayi: 1 -> 3 (node 2 bich se thoda alag ho gaya).curr.next = curr.next.next;curr (2) ka next ab 3 ke agle yaani 4 ko point karega.List ban gayi: 2 -> 4 -> 5prev.next.next = temp;Yeh dhyan se samjho: prev.next abhi kaun hai? Node 3 hai! Toh prev.next.next matlab node 3 ka next. Usme humne temp (node 2) daal diya.Yani 3 -> 2 ban gaya.Cycle 1 ke baad ka final structure: 1 (prev) -> 3 -> 2 (curr) -> 4 -> 5Notice karo: curr abhi bhi 2 par hi chipka hua hai, par node 3 kood kar prev ke turant baad aa gaya!
🔄 Cycle 2 (Jab i = 1)Abhi situation yeh hai: 1 (prev) -> 3 -> 2 (curr) -> 4 -> 5ListNode temp = prev.next;temp ab ban gaya node 3.prev.next = curr.next;prev (1) ka next ab direct curr.next (4) ko point karega.List ban gayi: 1 -> 4curr.next = curr.next.next;curr (2) ka next ab 4 ke agle yaani 5 ko point karega.List ban gayi: 2 -> 5prev.next.next = temp;prev.next abhi node 4 hai. Toh node 4 ka next ab temp (node 3) ban jayega.Yani 4 -> 3 ban gaya.Cycle 2 ke baad ka final structure: 1 (prev) -> 4 -> 3 -> 2 (curr) -> 5🔥 ResultLoop khatam! Ab list ko dhyaan se dekho: 1 -> 4 -> 3 -> 2 -> 5.Jo portion 2 -> 3 -> 4 tha, woh perfectly In-place reverse ho kar 4 -> 3 -> 2 ban chuka hai bina kisi extra space ke!


CycleShuruat ki Listtempprev.next ka badlavcurr.next ka badlavprev.next.next ka badlavFinal Structure
Cycle 11(p) -> 2(c) -> 3 -> 4 -> 521 -> 32 -> 43 -> 21(p) -> 3 -> 2(c) -> 4 -> 5
Cycle 21(p) -> 3 -> 2(c) -> 4 -> 531 -> 42 -> 54 -> 31(p) -> 4 -> 3 -> 2(c) -> 5
*/