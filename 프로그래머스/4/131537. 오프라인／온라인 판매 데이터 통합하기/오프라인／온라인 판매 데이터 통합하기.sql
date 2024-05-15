-- 코드를 입력하세요
with off as(
    select date_format(sales_date,'%Y-%m-%d') SALES_DATE, product_id PRODUCT_ID, null USER_ID, sum(sales_amount) SALES_AMOUNT
    from offline_sale
    where date_format(sales_date,'%Y-%m') = '2022-03'
    group by product_id, sales_date, offline_sale_id
), on_sale as(
    select date_format(sales_date,'%Y-%m-%d') SALES_DATE, product_id PRODUCT_ID, user_id USER_ID, sum(sales_amount) SALES_AMOUNT
    from online_sale
    where date_format(sales_date,'%Y-%m') = '2022-03'
    group by product_id, sales_date, user_id
), total as(
    select * from off
    union all
    select * from on_sale
)

select *
from total
order by sales_date, product_id, user_id