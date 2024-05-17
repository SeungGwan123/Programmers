-- 코드를 입력하세요
with member as(
    select user_id
    from user_info
    where date_format(joined,'%Y') = '2021'
), sale as(
    select date_format(sales_date,'%Y') YEAR,month(sales_date) MONTH, s.user_id user_id
    from online_sale s, member m
    where s.user_id = m.user_id
), group_sale as(
    select year, month, count(distinct user_id) puchased
    from sale
    group by year, month
)
select year YEAR, month MONTH, puchased PUCHASED_USERS, round(puchased/c.total_user,1) PUCHASED_RATIO
from group_sale, (select count(user_id) total_user from member) c
order by year, month