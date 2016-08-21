"""
# Installation
```
# Can't move by python3.5
$ pip2.7 install airflow
# To avoid 'ImportError: cannot import name HiveOperator'
$ mv /usr/local/lib/python3.5/site-packages/airflow/example_dags/example_twitter_dag.py ~/Desktop/
$ airflow initdb
$ airflow webserver -p 8080
# Access to http://localhost:8080/admin/
```

# Commands
```
$ airflow list_dags
$ airflow list_tasks -t __job_name__
$ airflow run __job_name__ print_date_0 2015-08-01
```
"""

from airflow import DAG
from airflow.operators.bash_operator import BashOperator
from datetime import datetime, timedelta

default_args = {
    'owner': 'inazo',
    'start_date': datetime(2016, 1, 1)
}

dag = DAG('__job_name__', default_args=default_args)

# tasks
t1 = BashOperator(task_id='print_date_0', bash_command='date',    dag=dag)
t2 = BashOperator(task_id='sleep',        bash_command='sleep 5', dag=dag)
t3 = BashOperator(task_id='print_date_1', bash_command='date',    dag=dag)

# schedule
t2.set_upstream(t1)
t3.set_upstream(t2)
