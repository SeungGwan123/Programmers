-- 코드를 입력하세요
with c 
as(
    select c.car_id, c.car_type, c.daily_fee
    from car_rental_company_car c, car_rental_company_rental_history h
    where c.car_id = h.car_id and c.car_type in ('SUV','세단') 
    # and date_format(h.start_date,'%Y-%m-%d') <= '2022-11-30' and date_format(h.end_date,'%Y-%m-%d') >= '2022-11-01')
    group by car_id
    having max(h.end_date) < '2022-11-01'
    ),
f as(
    select p.car_type, c.car_id, round(c.daily_fee*(1-p.discount_rate/100)*30,0) fee
    from car_rental_company_discount_plan p, c
    where p.car_type = c.car_type and p.duration_type like '30%'
)

select f.CAR_ID CAR_ID, f.CAR_TYPE CAR_TYPE, f.fee FEE
from f
where f.fee between 500000 and 2000000
order by f.fee desc, f.car_type asc, f.car_id desc