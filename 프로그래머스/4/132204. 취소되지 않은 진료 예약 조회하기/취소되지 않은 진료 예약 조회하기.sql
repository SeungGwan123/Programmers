-- 코드를 입력하세요
with no_cancel as(
    select apnt_ymd, apnt_no, pt_no, mcdp_cd, mddr_id
    from appointment
    where apnt_cncl_yn = 'N' and mcdp_cd = 'CS' and date_format(apnt_ymd,'%Y-%m-%d') = '2022-04-13'
)
select a.apnt_no APNT_NO, p.pt_name PT_NAME, a.pt_no PT_NO, a.mcdp_cd MDCP_CD, d.dr_name DR_NAME, a.apnt_ymd APNT_YMD
from no_cancel a, patient p, doctor d
where a.pt_no = p.pt_no and a.mddr_id = d.dr_id
order by apnt_ymd
