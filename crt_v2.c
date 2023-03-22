#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define HTML_TEMPLATE0 "<html><head><style>body {font-family: 'Roboto', sans-serif;background-size: cover;margin: 0;}.container {max-width: 800px;margin: 0 "
#define HTML_TEMPLATE1 "auto;max-height: 900mm;padding: 50px;background: linear-gradient(20deg, rgb(200, 211, 255) 30%%, rgb(255, 255, 255) 30.06%%, rgb(255, "
#define HTML_TEMPLATE2 "255, 255) 80.06%%,rgb(255, 249, 200) 80%%);box-shadow: 0 0 10px rgba(1, 1, 1, 0.331);}h1 {font-size: 36px;font-weight: bold;text-align: "
#define HTML_TEMPLATE3 "center;margin-bottom: 20px;color: #3e7394;}h6 {font-size: 10px;font-weight:100;text-align:end;margin-bottom: 20px;color: #000000;}a {text-decoration: none;}p "
#define HTML_TEMPLATE4 "{font-size: 20px;text-align: justify;line-height: 1.5;margin-bottom: 20px;color: #000000;}.signature {margin-top: 50px;text-align: center;}  button{border: none;color: rgb(32, 78, 70);padding: 15px 32px;text-align: center;text-decoration: none;display: inline-block;font-size: 16px;margin: 4px 2px;cursor: pointer;}@media print {@page "
#define HTML_TEMPLATE5 "{size: landscape;}button {display: none;}body {max-width: 800px;margin: 15 auto;max-height: 900mm;padding: 60px;background: linear-gradient(20deg, rgb(200, 211, 255)"
#define HTML_TEMPLATE6 " 30%%, rgb(255, 255, 255) 30.06%%, rgb(255, 255, 255) 80.06%%,rgb(255, 211, 160) 80%%);box-shadow: 0 0 10px rgba(1, 1, 1, 0.331);}}</style></head><body><center><div class=\"container\" "
#define HTML_TEMPLATE7 "id=\"certificate\"><h1>Certificate of Participation<br><br><br><br><br></h1><p>This is to certify that Mr/Ms <strong>"
#define HTML_TEMPLATE8 "%s</strong> bearing USN %s "
#define HTML_TEMPLATE9 "of third semester Electronics and Communication Engineering department has successfully completed one week online student development program from  12/12/22 "
#define HTML_TEMPLATE10 "to 20/12/22 on introduction to python organized by VAISHESHIKA student forum.</p><p>HOD,<br >Dr. K M SADYOJATHA</p><h6><a href=\"%s\" color=\"balck\">verify</a></h6><button "
#define HTML_TEMPLATE11 "onclick=\"printCertificate()\">Print Certificate</button><script>function printCertificate() {var printContents = document.getElementById('certificate').innerHTML;var originalContents = document.body.innerHTML;document.body.innerHTML = printContents;window.print();document.body.innerHTML = originalContents;}</script></div></body>Use system to print the document.don't use mobiles.<br>make sure<strong> background graphics</strong> is checked <br>didn't got <a href=\"image.png\">click here</a></html>"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s input_csv_file\n", argv[0]);
        return 1;
    }

    char *input_csv_file = argv[1];
    char data[100000],link[1000];
    strcpy(link,"https://epidotic-masts.000webhostapp.com/crts_py/");
    FILE *input_file = fopen(input_csv_file, "r");
    if (input_file == NULL) {
        printf("Error: could not open file '%s'\n", input_csv_file);
        return 1;
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input_file)) {
        char *name = strtok(line, ",");
        char *usn = strtok(NULL, ",");
        usn[strcspn(usn, "\r\n")] = '\0'; // remove trailing newline

        char filename[256];
        sprintf(filename, "%s.html", usn);

        FILE *output_file1 = fopen(filename, "w");
        if (output_file1 == NULL) {
            printf("Error: could not create file '%s'\n", filename);
            fclose(input_file);
            return 1;
        }
        fclose(output_file1);
        FILE *output_file=fopen(filename,"a");
        char html_content[MAX_LINE_LENGTH];
//        fprintf(output_file, "%s", html_content);
        sprintf(html_content, HTML_TEMPLATE0);   
        strcpy(data,html_content);
        fprintf(output_file, "%s", data);
        sprintf(html_content, HTML_TEMPLATE1);
        strcpy(data,html_content);
        fprintf(output_file, "%s", data);
        sprintf(html_content, HTML_TEMPLATE2);
        strcpy(data,html_content);
        fprintf(output_file, "%s", data);
        sprintf(html_content, HTML_TEMPLATE3);
        strcpy(data,html_content);
        fprintf(output_file, "%s", data);
        sprintf(html_content, HTML_TEMPLATE4);
        strcpy(data,html_content);
        fprintf(output_file, "%s", data);
        sprintf(html_content, HTML_TEMPLATE5);
        strcpy(data,html_content);
        fprintf(output_file, "%s", data);
        sprintf(html_content, HTML_TEMPLATE6);
        strcpy(data,html_content);
        fprintf(output_file, "%s", data);
        sprintf(html_content, HTML_TEMPLATE7);
        strcpy(data,html_content);
        fprintf(output_file, "%s", data);
        sprintf(html_content, HTML_TEMPLATE8, name, usn);
        strcpy(data,html_content);
        fprintf(output_file, "%s", data);
        sprintf(html_content, HTML_TEMPLATE9);
        strcpy(data,html_content);
        fprintf(output_file, "%s", data);
        strcpy(link,filename);
        sprintf(html_content, HTML_TEMPLATE10, link);
        strcpy(data,html_content);
        fprintf(output_file, "%s", data);
        sprintf(html_content, HTML_TEMPLATE11);
        strcpy(data,html_content);
        fprintf(output_file, "%s", data);
        //fprintf(output_file, "%s", html_content);
        //fputs(html_content, output_file);
        fclose(output_file);
    }

    fclose(input_file);

    return 0;
}
