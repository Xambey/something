function matrix()
    a = [4 5 6; 1 2 3; 7 8 9]
    [b, i, j] = inputFile('matrix1.txt')
    outputFile(a, 3, 3, 'matrix2.txt')
    key = input('����:\n1)���� ������� � ����������\n2)�������� ������\n3)��������� ������\n4)��������� ������\n5)���������������� �������\n6)�������������� �������(������� �14):\n7)��� ������\n')
	while (key > 0)
		if key == 1
            a = ReadKeyboard();
            outputFile(a, length(a), length(a), 'matrix2.txt')
        end
		if key == 2
             fprintf('�������');
             a
             fprintf('�������');
             b
             if length(a) == length(b)
                disp('����� ������ c �����:');
                c = a + b
             else
                disp('������! ������� ������ ���� ����������� �������')
                key = input('����:\n1)���� ������� � ����������\n2)�������� ������\n3)��������� ������\n4)��������� ������\n5)���������������� �������\n6)�������������� �������(������� �14):\n7)��� ������\n')
                pause();
                continue;
             end
        end
		if key == 3
             fprintf('�������');
             a
             fprintf('�������');
             b
			if length(a) == length(b)
                
                disp('����� ������ c �����:');
                c = a + b
            else
                disp('������! ������� ������ ���� ����������� �������')
                key = input('����:\n1)���� ������� � ����������\n2)�������� ������\n3)��������� ������\n4)��������� ������\n5)���������������� �������\n6)�������������� �������(������� �14):\n7)��� ������\n')
                pause()
                continue;
            end
        end
		if key == 4
             fprintf('�������');
             a
             fprintf('�������');
             b
			disp('������������ ������ c �����:');
            c = a * b
        end
		if key == 5
            fprintf('�������');
            a
			disp('����������������� ������� �����:');
            a'
        end
        if key == 6 
			fprintf('�������');
            a
            result = minCol(a, 3, 3)
        end
        if key == 7
            break;
        end
		pause()
		key = input('����:\n1)���� ������� � ����������\n2)�������� ������\n3)��������� ������\n4)��������� ������\n5)���������������� �������\n6)�������������� �������(������� �14):\n7)��� ������\n')
    end
end

function print(matrix)
    matrix
end

function c = ReadKeyboard() 
    c = input('������� �������:');
    disp('���� �������: ');
    print(c);
end

function c = read(file)
    [f,c] = fopen(file, 'rt');
    if f ~=-1
        c = ' ';
        while feof(f) == 0
            line = fgetl(f);
            c = char(c, line);
        end
        fclose(f);
    end
end

function [ c, n, m ] = inputFile(file)

f = fopen(file, 'rt');
n = fscanf(f,'%d',1);
m = fscanf(f,'%d',1);
for i=1:n
    for j=1:m
        c(i,j) = fscanf(f,'%f',1); 
    end
end
fclose(f);
end

function outputFile( c, n, m, file)
f = fopen(file, 'wt'); 
for i=1:n
    for j=1:m
        fprintf(f,'%f\t',c(i,j));  
    end
    fprintf(f,'\n');
end
fclose(f);
end

function c = minCol(c, n, m)
        jmin = min(min(c))  
        i = 1;
        k = 1;
        t = 0;
		for k=1:k<m-1
			for i=1:i<=n-i-1
				if c(i,jmin) > c(i+1,jmin)                  
                      t=c(i,:);
                      c(i,:)=c(i+1,:);
                      c(i+1,:)=t;
                end
            end
        end
end
