# Write your MySQL query statement below
#group by customer_id
#count (visit_id)
#join table
select v.customer_id,count(v.visit_id) as count_no_trans  from 
visits v LEFT join transactions t on t.visit_id=v.visit_id
where t.transaction_id is null
group by v.customer_id;