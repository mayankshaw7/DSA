# Write your MySQL query statement below
select p.product_id,
IFNULL(round(sum(us.units*p.price)/sum(us.units),2),0)as average_price
from prices p 
left join 
UnitsSold as us on us.product_id=p.product_id
and us.purchase_date between start_date and end_date
group by product_id
order by product_id;