import requests
r = requests.get('https://api.clever.com/v1.1/sections', headers={'Authorization':'Bearer DEMO_TOKEN'})
m_data = r.json().get('data') 
m_count = {}
each_info = {}
for each_data in m_data:
    each_info = each_data.get('data')
    if each_info.get('course_name') not in m_count:
        m_count[each_info.get('course_name')] = 0
    m_count[each_info.get('course_name')] = m_count[each_info.get('course_name')]+len(each_info.get('students'))

sum = 0
count = 0
for key in m_count:
    count += 1
    sum += m_count[key]
    print(key, m_count[key]) 

print(sum/count)

