function varargout = adimat_diff_max3(varargin)

  [varargout{2}, varargout{3}]= max(varargin{2});
  if numel(varargout{3}) == 1
    varargout{1} = varargin{1}(:, varargout{3});
  else
    varargout{1} = d_zeros(varargout{2});
    for i=1:numel(varargout{3})
      varargout{1}(:, i) = varargin{1}(:, varargout{3}(i), i);
    end
  end
end
% automatically generated from $Id: derivatives-vdd.xml 3983 2013-12-21 11:20:23Z willkomm $
