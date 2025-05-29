import mysql from 'mysql2';

const connection = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'cheryne0',
    database: 'Clients'
});

// ** READ

function readClient(table: string, id: number, categorie: string) {
    const sql = `SELECT ?? FROM ?? WHERE id = ?`;

    connection.query(sql, [categorie, table, id], (err, result) => {
        if (err) {
            console.error('Error fetching data:', err);
            return;
        }
         console.log(result);
        });
}

// ** CREATE
interface Employee {
  email: string;
  name: string;
  surname: string;
  password: string;
  birth_date: string;
  gender: string;
  work: string;
  picture: string;
}

function createCoaches(coaches: Employee) {
  const sql = `INSERT INTO employees (email, name, surname, password, birth_date, gender, work, picture)
        VALUES (?, ?, ?, ?, ?, ?, ?, ?)`;
  const params = [
      coaches.email,
      coaches.name,
      coaches.surname,
      coaches.password,
      coaches.birth_date,
      coaches.gender,
      coaches.work,
      coaches.picture
  ];

  connection.query(sql, params, (err, result) => {
      if (err) {
          console.error('Error inserting data:', err);
          return;
      }
      console.log('Employee created with ID:', result);
  });
}

// TODO UPDATE

function updateValue(table: string, id: number, categorie: string, newValue: any) {
  const sql = `UPDATE ?? SET ?? = ? WHERE id = ?`;

  connection.query(sql, [table, categorie, newValue, id], (err, result) => {
      if (err) {
          console.error('Error updating data:', err);
          return;
      }
      console.log('Number of records updated:', result);
  });
}

// TODO DELETE

function deleteValues(table: string, id_todelete: number, categorie: string) {
  const sql = `UPDATE ?? SET ?? = NULL WHERE id = ?`;

  connection.query(sql, [table, categorie, id_todelete], (err, result) => {
      if (err) {
          console.error('Error updating data:', err);
          return;
      }
      console.log('Number of records updated:', result);
  });
}

function deleteCoach(table: string, id_todelete: number) {
  const sql = `DELETE FROM ?? WHERE id = ?`;

  connection.query(sql, [table, id_todelete], (err, result) => {
      if (err) {
          console.error('Error updating data:', err);
          return;
      }
      console.log('Number of records updated:', result);
  });
}

function main() {
   //  readClient('customers', 1, 'email')

    //  createCoaches({
    //      email: 'stella.doe@example.com',
    //      name: 'stella',
    //      surname: 'star',
    //      password: 'password1234',
    //      birth_date: '1985-06-15',
    //      gender: '1',
    //      work: 'star',
    //      picture: 'profile.jpg'
    //  });
//    updateValue('employees', 3, 'name', 'Camila');
    //deleteCoach('employees', 3);
    connection.end();
}

main();
